#ifndef SORT_H
#define SORT_H

#include <ctype.h>
#include <assert.h>
#include <string.h>

#include "text.h"

unsigned char *skip_extra_symbols (const char *arr, int *index, const int step, const int len);
void my_shellsort (void *ptr, size_t count, size_t size, comparer_t *str_compare);
void swap (void *ptr1, void *ptr2, size_t size);

#endif /* SORT_H */
//
