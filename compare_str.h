#ifndef COMPARE_STR_H
#define COMPARE_STR_H

#include <ctype.h>
#include <assert.h>
#include <string.h>

#include "consts.h"

int compare_str (const void *str1, const void *str2);
int compare_str_backwards (const void *str1, const void *str2);
int my_shellsort (struct Strings *strings, int nlines, int (*str_compare) (const void *, const void *));

#endif /* COMPARE_STR_H */
