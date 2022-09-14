#include "print_sort.h"
#include "struct.h"

void print_lex_sort (Strings strings[], const int nlines, FILE *file)
{
    assert (strings);
    assert (file);

    for (int i = 0; i < nlines; i++)
    {
        fputs (strings[i].p, file);
        //printf ("%s\n", strings [i]);
        fputc ('\n', file);
    }
}
