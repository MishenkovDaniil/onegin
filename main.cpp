#include <sys\stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <assert.h>
#include <errno.h>

#include "text.h"
#include "sort.h"
#include "io.h"

int main (int argc, const char *argv[])
{
    setlocale (LC_ALL, "Rus");
    setlocale (LC_NUMERIC, "Eng");

    extern int errno = 0;
    int errnosave = 0;

    if (argc == 1)
    {
        printf ("enter source_file, sort type and dest_file through a space\n"
                "\t sort types:\n"
                "\t no sort        - no\n"
                "\t ordinary cort  - ordinary\n"
                "\t backwards sort - backwards");
        return 0;
    }
    else if (argc != 4)
    {
        printf ("not readable: enter source_file sort type and dest_file");
        return 0;
    }

    int file_size = get_file_size(argv[1]);
    if (file_size)
    {
       errorsave = errno;
       return errnosave;
    }

    FILE *src_file = fopen (argv[1], "rb");
    if (src_file == nullptr)
    {
        errorsave = errno;
        perror ("opening of file failed");
        return errnosave;
    }

    char *text = (char *)calloc (1, sizeof(char)*(file_size + 2));
    if (text == nullptr)
    {
        errorsave = errno;
        perror ("error message");
        return errnosave;
    }

    int nlines = 0;
    nlines = read_in_buf (src_file, text, &nlines, file_size);

    Line *lines = (Line *)calloc (nlines, sizeof (Line));
    if (lines == nullptr)
    {
        errorsave = errno;
        perror ("error message");
        return errnosave;
    }

    /*Text orig = {};
    split_text(&orig, buf);

    Text sorted = {};
    split_text()

    sort(sorted)

    print_text();

*/


    split_text (text, lines);

    //my_shellsort (lines, nlines, &compare_str);

    FILE *dst_file = fopen (argv[3], "w");

    if (strcmp (argv[2], "no") == 0)
    {
        print_lines (lines, nlines, dst_file);
    }
    if (strcmp (argv[2], "ordinary") == 0)
    {
        my_shellsort (lines, nlines, sizeof (lines[0]), &compare_str);
        print_lines (lines, nlines, dst_file);
    }
    if (strcmp (argv[2], "backwards") == 0)
    {
        qsort (lines, nlines, sizeof (lines[0]), &compare_str_backwards);
        print_lines (lines, nlines, dst_file);
    }

    free (lines);
    // free_text() αστεπ
    free (text);

    return 0;
}


