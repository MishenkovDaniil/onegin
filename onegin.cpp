#include <sys\stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <assert.h>

#include "compare_str.h"
#include "read_onegin.h"
#include "print_sort.h"
#include "consts.h"

int main ()
{
    setlocale (LC_ALL, "Rus");
    setlocale (LC_NUMERIC, "Eng");

    int file_size = onegin_size();
    if (file_size == -1)
    {
        return -1;
    }

    FILE *src_file = fopen (ONEGIN, "rb");
    assert(src_file);

    char *pstr = (char *)calloc (1, sizeof(char)*(file_size + 2));
    assert (pstr);

    int nlines = 0;
    nlines = read_file (src_file, pstr, &nlines, file_size);

    Strings *strings = (Strings *)calloc (nlines, sizeof (Strings));
    assert (strings);

    read_by_struct (pstr, strings);

    my_shellsort (strings, nlines, &compare_str);

    FILE *dst_file_1 = fopen (DST, "w");
    fclose (dst_file_1);

    FILE *dst_file_2 = fopen (DST, "a");
    print_lex_sort (strings, nlines, dst_file_2);

    qsort (strings, nlines, sizeof (strings[0]), &compare_str_backwards);
    print_lex_sort (strings, nlines, dst_file_2);

    print_original (strings, nlines, dst_file_2);

    free (strings);
    free (pstr);

    return 0;
}


