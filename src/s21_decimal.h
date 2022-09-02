#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

// #include "decimal_core.h"

typedef struct {
    int bits[4];
} s21_decimal;


//  comparison
int s21_is_equal(s21_decimal decim1, s21_decimal decim2);
int s21_is_not_equal(s21_decimal decim1, s21_decimal decim2);
int s21_is_greater_or_equal(s21_decimal decim1, s21_decimal decim2);
int s21_is_greater(s21_decimal decim1, s21_decimal decim2);
int s21_is_less_or_equal(s21_decimal decim1, s21_decimal decim2);
int s21_is_less(s21_decimal decim1, s21_decimal decim2);



#endif  //  SRC_S21_DECIMAL_H_
