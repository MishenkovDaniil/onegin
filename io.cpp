#include <sys\stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "io.h"
#include "text.h"

int count_symbols (const char *buf, size_t size, const char ch)
{
    int counter = 0;
    for (int i = 0; i <= size; i++)
    {
        if (buf[i] == ch)
        {
            counter++;
        }
    }

    return counter;
}

void normalise_text (char *buf, const char ch_1, const char ch_2)
{
    for (int i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] == ch_1)
        {
            buf[i] = ch_2;
        }
    }
}

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

    //char *buf = nullptr;
    //setvbuf (src_file, buf, _IOFBF, file_size);

    int n_symbols = fread (text, sizeof (char), file_size, src_file);
    if (n_symbols < file_size)
    {
        fprintf (stderr, "error message: reading of source file failed (%d out of %d)", n_symbols, file_size);

        return 0;
    }

    //setvbuf (src_file, buf, _IONBF, 0);

    text[file_size] = '\n';
    text[file_size + 1] = '\0';

    *nlines = count_symbols (text, file_size, '\n');

    return *nlines;
}

int split_text (char *text, Line *lines)
{
    assert (text);
    assert (lines);

    int line = 0;
    int start = 0;
    int actual_symbol = 0;

    normalise_text (text, '¸', 'å');

    while (text[start] != '\0')
    {
        for (actual_symbol = start; text[actual_symbol] != '\0'; actual_symbol++)
        {
            if (text[actual_symbol] == '\n')
            {
                text[actual_symbol] = '\0';

                lines[line].start = &text[start];
                lines[line].len = &text[actual_symbol] - &text[start];

                line++;

                start = ++actual_symbol;
            }
        }
    }

    return 0;
}

void print_lines (Line *lines, const int nlines, FILE *file)
{
    assert (lines);
    assert (file);

    for (int i = 0; i < nlines; i++)
    {
        fputs (lines[i].start, file);
    }
}

