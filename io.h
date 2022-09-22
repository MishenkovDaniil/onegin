#ifndef IO_H
#define IO_H

#include <assert.h>
#include <stdio.h>

#include "text.h"

int count_symbols (const char *buf, size_t size, const char ch);
void normalise_text (char *buf, const char ch_1, const char ch_2);
int get_file_size (const char *file_name);
int read_in_buf (FILE *src_file, char *text, int *nlines, int file_size);
int split_text (char *text, Line *lines);

void print_lines (Line *lines, const int nlines, FILE *file);

#endif /* IO_H */
