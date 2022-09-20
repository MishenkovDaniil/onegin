#include <sys\stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "io.h"
#include "text.h"

int get_file_size (const char *file_name)
{
    struct stat buf = {};

    stat(file_name, &buf);
    int errnosave = 0;

    if (errno)
    {
        errnosave = errno;
        perror ("stat() failed");
        return errnosave;
    }

    return buf.st_size;
}

int read_in_buf (FILE *src_file, char *text, int *nlines, int file_size)
{
    assert (src_file);
    assert (text);
    assert (nlines);

    int n_symbols = fread (text, sizeof (char), file_size, src_file);
    if (n_symbols < file_size)
    {
        fprintf (stderr, "error message: reading of source file failed");

        return 0;
    }

    text[file_size] = '\n';
    text[file_size + 1] = '\0';

    for (int i = 0; i <= file_size; i++)
    {
        if (text[i] == '\n')
        {
            (*nlines)++;
        }
    }

    return *nlines;
}

// split text array of lines
// split_text(Text text, buf)
int split_text (char *text, Line *lines)
{
    assert (text);
    assert (lines);

    int line = 0;
    int start = 0;
    int str_number = 0;
    int actual_symbol = 0;

// calloc lines
    while (text[start] != '\0')
    {
        for (actual_symbol = start; text[actual_symbol] != '\0'; actual_symbol++)
        {
            if (text[actual_symbol] == '¸')
            {
                text[actual_symbol] = 'å';
            }

            if (text[actual_symbol] == '\n')
            {
                text[actual_symbol] = '\0';

                lines[line].start = &text[start];
                //lines[line].number = str_number++;
                lines[line].len = &text[actual_symbol] - &text[start];
                //printf ("%s\n", strings[line].string);
                line++;

                start = ++actual_symbol;
            }
        }
    }

    return 0;
}

//void print_text(const Text *text)
//{}

void print_lines (Line *lines, const int nlines, FILE *file)
{
    assert (lines);
    assert (file);

    for (int i = 0; i < nlines; i++)
    {
        fputs (lines[i].start, file);
    }
}

/*
void print_original (Line *lines, int nlines, FILE *file)
{
    assert (lines);
    assert (file);

    for (int i = 0; i < nlines; i++)
    {
        for (int j = 0; j < nlines; j++)
        {
            if (lines[j].number == i)
            {
                fputs (lines[j].string, file);
            }
        }
    }
}
*/
