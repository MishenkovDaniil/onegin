#ifndef COMPARE_STR_H
#define COMPARE_STR_H

#include <ctype.h>
#include <assert.h>
#include <string.h>

#include "consts.h"

unsigned char skip_extra_symbols (const char *arr, int *index, const int step);
int compare_str (const void *str1, const void *str2);
int compare_str_backwards (const void *str1, const void *str2);
int my_shellsort (struct Strings *strings, int nlines, str_compare_t *str_compare);
int uni_compare (const char *arr1, int strlen_1, const char *arr2, int strlen_2, const int step);


#endif /* COMPARE_STR_H */
