#ifndef READ_STR_H
#define READ_STR_H

#include <assert.h>
#include <stdio.h>

int read_by_str (char *pstr, char **strings);
int read_file (FILE *src_file, char *pstr, int *nlines, int *maxlen);

#endif /* READ_STR_H */
