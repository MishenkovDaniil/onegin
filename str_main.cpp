#include <sys\stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <strings.h>
#include <assert.h>
#include <ctype.h>

const char Onegin[] = "Eugine Onegin.txt";

int read_file (FILE *src_file, char *pstr, int *nlines, int *maxlen);
int read_by_str (char *pstr, char **strings);
int compare_str (const void *str1, const void *str2);
void print_lex_sort (char **strings, const int nlines, FILE *file);

struct stat buf = {};

int main ()
{
    setlocale (LC_ALL, "Rus");


    if ((stat (Onegin, &buf)) == -1)
    {
        printf ("ERROR: stat");
    }
    else
    {
    FILE *src_file = fopen (Onegin, "r");
    assert(src_file);

    int nlines = 0;
    int maxlen = 0;

    char *pstr = (char *)malloc (1 * buf.st_size);

    read_file (src_file, pstr, &nlines, &maxlen);

    char *strings[nlines];

    read_by_str (pstr, strings);

    qsort ((void **)strings, nlines, sizeof (strings[0]), &compare_str);

    /*for (int i = 0; i < nlines; i++)
    {
        printf ("%s\n", strings[i]);
    }*/

    FILE *dst_file = fopen ("new onegin.txt", "w");

    print_lex_sort (strings, nlines, dst_file);

    free (pstr);
    }

    return 0;
}

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

int read_by_str (char *pstr, char **strings)
{
    assert (pstr);
    assert (strings);

    int line = 0;
    int actual_symbol = 0;
    int start = 0;

    while (pstr[start] != '\0')
    {
        for (actual_symbol = start; pstr[actual_symbol] != '\n'; actual_symbol++)
        {
            if (pstr[actual_symbol] == '\0')
            {
                strings[line] = &pstr[start];

                return 0;
            }
        }
        pstr[actual_symbol] = '\0';

        strings[line] = &pstr[start];

        line++;

        start = ++actual_symbol;

    }

    return 0;
}

int compare_str (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = *(const char **) str1;
    const char *arr2 = *(const char **) str2;

    assert (arr1);
    assert (arr2);

    while ((!(isalnum (*arr1))) && (*arr1 != '\0'))//
    {
        arr1++;
    }
    while ((!(isalnum (*arr2))) && (*arr2 != '\0'))//
    {
        arr2++;
    }

    while ((*arr1++ == *arr2++) && (*arr1 != '\0') && (*arr2 != '\0'));//
        ;

    return *--arr1 - *--arr2;
}

void print_lex_sort (char **strings, const int nlines, FILE *file)
{
    assert (strings);
    assert (file);

    for (int i = 0; i < nlines; i++)
    {
        fputs (strings[i], file);
        printf ("%s\n", strings [i]);
        fputc ('\n', file);
    }
}
