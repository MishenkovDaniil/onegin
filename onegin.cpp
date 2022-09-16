#include <sys\stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <assert.h>

#include "compare_str.h"
#include "read_onegin.h"
#include "print_sort.h"
#include "consts.h"

struct stat buf = {};

int main ()
{
    setlocale (LC_ALL, "Rus");

    if ((stat (ONEGIN, &buf)) == -1)
    {
        printf ("ERROR: stat");
    }
    else
    {
    FILE *src_file = fopen (ONEGIN, "rb");
    assert(src_file);

    int nlines = 0;
    int maxlen = 0;

    char *pstr = (char *)malloc (1 * buf.st_size);
    read_file (src_file, pstr, &nlines, &maxlen);

    Strings *strings = (struct Strings *)malloc (sizeof(struct Strings) * nlines);
    read_by_struct (pstr, strings);

    my_shellsort (strings, nlines, &compare_str);
    /////qsort (strings, nlines, sizeof (strings[0]), &compare_str);

    FILE *dst_file_1 = fopen (DST, "w");
    fclose (dst_file_1);

    FILE *dst_file_2 = fopen (DST, "a");

    print_lex_sort (strings, nlines, dst_file_2);

    qsort (strings, nlines, sizeof (strings[0]), &compare_str_backwards);
    print_lex_sort (strings, nlines, dst_file_2);

    print_original (strings, nlines, dst_file_2);

    free (pstr);
    }

    return 0;
}


