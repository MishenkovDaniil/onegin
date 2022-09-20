#ifndef IO_H
#define IO_H

#include <assert.h>
#include <stdio.h>

#include "text.h"

int get_file_size (const char *file_name);
int read_in_buf (FILE *src_file, char *text, int *nlines, int file_size);
int split_text (char *text, Line *lines);

void print_lines (Line *lines, const int nlines, FILE *file);

#endif /* IO_H */
