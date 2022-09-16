#include "print_sort.h"
#include "struct.h"

void print_lex_sort (Strings *strings, const int nlines, FILE *file)
{
    assert (strings);
    assert (file);

    for (int i = 0; i < nlines; i++)
    {
        fputs (strings[i].p, file);
    }
}

void print_original (Strings *strings, int nlines, FILE *file)
{
    assert (strings);
    assert (file);

    for (int i = 0; i < nlines; i++)
    {
        for (int j = 0; j < nlines; j++)
        {
            if (strings[j].number == i)
            {
                fputs (strings[j].p, file);
            }
        }
    }
}
