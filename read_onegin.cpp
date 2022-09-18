#include <sys\stat.h>
#include <stdio.h>
#include <stdlib.h>

#include "read_onegin.h"
#include "consts.h"

int onegin_size ()
{
    struct stat buf = {};

    if ((stat (ONEGIN, &buf)) == -1)
    {
        perror ("stat() failed");

        return -1;
    }

    return buf.st_size;
}

int read_file (FILE *src_file, char *pstr, int *nlines, int file_size)
{
    assert (src_file);
    assert (pstr);
    assert (nlines);

    fread (pstr, sizeof (char), file_size, src_file);

    pstr[file_size] = '\n';
    pstr[file_size + 1] = '\0';

    for (int i = 0; i <= file_size; i++)
    {
        if (pstr[i] == '\n')
        {
            (*nlines)++;
        }
    }

    return *nlines;
}

int read_by_struct (char *pstr, Strings *strings)
{
    assert (pstr);
    assert (strings);

    int line = 0;
    int start = 0;
    int str_number = 0;
    int actual_symbol = 0;

    while (pstr[start] != '\0')
    {
        for (actual_symbol = start; pstr[actual_symbol] != '\0'; actual_symbol++)
        {
            if (pstr[actual_symbol] == '¸')
            {
                pstr[actual_symbol] = 'å';
            }

            if (pstr[actual_symbol] == '\n')
            {
                pstr[actual_symbol] = '\0';

                strings[line].string = &pstr[start];
                strings[line].number = str_number++;
                strings[line].size = &pstr[actual_symbol] - &pstr[start];
                //printf ("%s\n", strings[line].string);
                line++;

                start = ++actual_symbol;
            }
        }
    }

    return 0;
}
