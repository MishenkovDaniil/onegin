#include "read_onegin.h"
#include "consts.h"

int read_file (FILE *src_file, char *pstr, int *nlines, int *maxlen)
{
    int c = 0;
    int i = 0;
    int len = 0;

    while ((c = fgetc (src_file)) != EOF)
    {
        *(pstr + i) = c;

        len++;
        i++;

        if (c == '\n')
        {
            (*nlines)++;

            if (len > *maxlen)
            {
                *maxlen = len;
            }

            len = 0;
        }
    }
    *(pstr + i) = '\0';

    return i;
}

int read_by_struct (char *pstr, Strings *strings)
{
    assert (pstr);
    assert (strings);

    int line = 0;
    int actual_symbol = 0;
    int start = 0;
    int str_number = 0;

    while (pstr[start] != '\0')
    {
        for (actual_symbol = start; pstr[actual_symbol] != '\n'; actual_symbol++)
        {
            if (pstr[actual_symbol] == '¸')
            {
                pstr[actual_symbol] = 'å';
            }

            if (pstr[actual_symbol] == '\0')
            {
                strings[line].p = &pstr[start];
                strings[line].number = str_number++;
                strings[line].size = &pstr[actual_symbol] - &pstr[start];

                return 0;
            }
        }
        pstr[actual_symbol] = '\0';

        strings[line].p = &pstr[start];
        strings[line].number = str_number++;
        strings[line].size = &pstr[actual_symbol] - &pstr[start];

        line++;

        start = ++actual_symbol;

    }

    return 0;
}
