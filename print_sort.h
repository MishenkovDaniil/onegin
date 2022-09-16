#ifndef PRINT_SORT_H
#define PRINT_SORT_H

#include <stdio.h>
#include <assert.h>

#include "consts.h"

void print_lex_sort (Strings *strings, const int nlines, FILE *file);
void print_original (Strings *strings, int nlines, FILE *file);

#endif /* PRINT_SORT_H */
