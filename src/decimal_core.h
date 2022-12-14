#ifndef SRC_DECIMAL_CORE_H_
#define SRC_DECIMAL_CORE_H_

#include <stdio.h>
#include "s21_decimal.h"

#define _2(bit) (1 << (bit))

#define BITS 4
#define BITS_IN_INT 32
#define INFO_BIT 3
#define ALL_BIT (BITS_IN_INT * BITS)
#define START_EXP_BIT 16
#define END_EXP_BIT 23
#define ZERO_BIT 0
#define SIGN_BIT 31
#define OK 0
#define ERR 1
#define MAX_EXP 28

#define COLOR_HEADER "\033[95m"
#define COLOR_BLUE "\033[94m"
#define COLOR_CYAN "\033[96m"
#define COLOR_GREEN "\033[92m"
#define COLOR_ORANGE "\033[93m"
#define COLOR_RED "\033[91m"
#define COLOR_END "\033[0m"

int bit_on(int bits, int bit);
int bit_off(int bits, int bit);
int bit_swap(int bits, int bit);
int bit_is(int bits, int bit);
int get_global_bit(s21_decimal decim, int gbit);
int set_global_bit(s21_decimal* decim, int gbit, int new_bit);
int get_bits(s21_decimal decim, int gbit);
int get_bit(int bits, int bit);
int check_sign(s21_decimal decim);
int chang_sign(s21_decimal* decim);
int set_sign(s21_decimal *decim, int sign);
s21_decimal nullify_all_decimal(s21_decimal *decim);
int is_null_decimal(s21_decimal decim);
int set_bit(int bits, int bit, int new_bit);
// for debug
void print_decimal_bin(s21_decimal decim);
void print_decimal_int(s21_decimal decimal_int);
int get_exp(s21_decimal decim);
int set_exp(s21_decimal* decim, int new_exp);
int swap_int(int* value1, int* value2);
int truncate_to_exp(s21_decimal decim, int new_exp, s21_decimal* result_decimal);

int swift_bits_right(int bits, int number);
s21_decimal bit_swift_right(s21_decimal decim, int number);
int bit_swift_left(s21_decimal decim, int number, s21_decimal* result);
s21_decimal bit_exclusive_or(s21_decimal decim1, s21_decimal decim2);
s21_decimal bit_and(s21_decimal decim1, s21_decimal decim2);
s21_decimal bit_negative(s21_decimal decim);
s21_decimal bit_or(s21_decimal decim1, s21_decimal decim2);

int bank_round(s21_decimal *number, int n);
int bank_rounding(int a);
int balancing(s21_decimal *a, s21_decimal *b);
int shifting(s21_decimal *a, int n);

#endif  //  SRC_DECIMAL_CORE_H_
