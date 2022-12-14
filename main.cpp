#include <sys\stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <assert.h>
#include <errno.h>

#include "text.h"
#include "sort.h"
#include "io.h"

int VERBOSE = 0;

int main (int argc, const char *argv[])
{
    setlocale (LC_ALL, "Rus");
    setlocale (LC_NUMERIC, "Eng");

    int errnosave = 0;

    if (argc == 1)
    {
        printf ("enter source_file, sort type, dest_file and verbose through a space\n"
                "sort types:\n"
                "\t no sort        - no\n"
                "\t ordinary cort  - ordinary\n"
                "\t backwards sort - backwards\n"
                "verbose values:\n"
                "\t 0 - to see info about all errors\n"
                "\t 1 - to see only necessary errors");
        return 0;
    }
    else if (argc != 5)
    {
        printf ("not readable: enter source_file sort type, dest_file and verbose");
        return 0;
    }
    else if (*(argv[4]) < '0' || *(argv[4]) > '1')
    {
        printf ("verbose must be a number from 0 to 1");
    }

    VERBOSE = *(argv[4]) - '0';

    int file_size = get_file_size(argv[1]);
    if (!file_size)
    {
       return file_size;
    }

    FILE *src_file = fopen (argv[1], "rb");
    if (src_file == nullptr)
    {
        errnosave = errno;
        perror ("opening of file failed");

        return errnosave;
    }

    char *text = (char *)calloc (1, sizeof(char)*(file_size + 2));
    if (text == nullptr)
    {
        fprintf (stderr, "error message: out of memory");
        return 0;
    }

    int nlines = 0;
    nlines = read_in_buf (src_file, text, &nlines, file_size);
    if (!nlines)
    {
        return 0;
    }

    Line *lines = (Line *)calloc (nlines, sizeof (Line));
    if (lines == nullptr)
    {
        fprintf (stderr, "error message: out of memory");
        return 0;
    }

    split_text (text, lines);

    FILE *dst_file = fopen (argv[3], "w");

    if (strcmp (argv[2], "no") == 0)
    {
        print_lines (lines, nlines, dst_file);
    }
    if (strcmp (argv[2], "ordinary") == 0)
    {
        my_shellsort (lines, nlines, sizeof(lines[0]), &compare_str);
        print_lines (lines, nlines, dst_file);
    }
    if (strcmp (argv[2], "backwards") == 0)
    {
        qsort (lines, nlines, sizeof (lines[0]), &compare_str_backwards);
        print_lines (lines, nlines, dst_file);
    }

    if (fclose (src_file))
    {
        if (!VERBOSE)
        {
            fprintf (stderr, "error message: cannot close source file");

            return 0;
        }
    }
    if (fclose (dst_file))
    {
        if (!VERBOSE)
        {
            fprintf (stderr, "error message: cannot close dest file");

            return 0;
        }
    }


    free (lines);
    free (text);

    return 0;
}
