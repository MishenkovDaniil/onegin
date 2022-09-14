#ifndef READ_ONEGIN_H
#define READ_ONEGIN_H

#include <assert.h>
#include <stdio.h>

#include "consts.h"

int read_by_struct (char *pstr, Strings *strings);
int read_file (FILE *src_file, char *pstr, int *nlines, int *maxlen);

#endif /* READ_ONEGIN_H */
