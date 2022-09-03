#include "decimal_core.h"
#include "s21_decimal.h"

int s21_from_int_to_decimal(int src_int, s21_decimal *dst_decimal) {
  nullify_all_decimal(dst_decimal);
  int error_mark = 0;
  if (!dst_decimal)
    error_mark = 1;
  else if (src_int < 0) {
    src_int = -src_int;
    chang_sign(dst_decimal);
  }
  dst_decimal->bits[0] = src_int;
  return error_mark;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int result = 0;
    int ten_pow = get_exp(src);
    if (!dst) {
        result = 1;
    } else if (ten_pow > 28) {
        *dst = 0;
        result = 1;
    } else {
        s21_truncate(src, &src);

        for (int i = 1; i < 3; i++) {
            for (int j = 0; j < 16; j++) {
                if (get_bit(src.bits[i], j) == 1) {
                    result = 1;
                    break;
                }
            }
            if (result == 1) {
                break;
            }
        }

        if (result == 0) {
            if (check_sign(src) == 1)
                *dst = 0 - src.bits[0];
            else
                *dst = src.bits[0];
            if (*dst) *dst = set_bit(*dst, 31, check_sign(src));

        }
    }
    return result;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
    *result = bit_swift_right(value, get_exp(value));
    set_exp(result, 0);
    return 0;
}

