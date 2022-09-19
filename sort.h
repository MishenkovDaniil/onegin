#ifndef SORT_H
#define SORT_H

#include <ctype.h>
#include <assert.h>
#include <string.h>

#include "text.h"

unsigned char *skip_extra_symbols (const char *arr, int *index, const int step, const int len);
void my_shellsort (Line *lines, int nlines, comparer_t *str_compare);
void swap (void *ptr1, void *ptr2);

#endif /* SORT_H */
