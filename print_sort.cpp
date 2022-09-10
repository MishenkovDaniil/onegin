#include "print_sort.h"

void print_lex_sort (char **strings, const int nlines, FILE *file)
{
    assert (strings);
    assert (file);

    for (int i = 0; i < nlines; i++)
    {
        fputs (strings[i], file);
        //printf ("%s\n", strings [i]);
        fputc ('\n', file);
    }
}
