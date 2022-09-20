#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text.h"
#include "sort.h"

unsigned char *skip_extra_symbols (const char *arr, int *index, const int step, const int len)
{
    unsigned char *symbol = nullptr;

    for (symbol = (unsigned char*)(arr + (*index)); abs(*index) < len;)
    {
        if (isalnum (*symbol))
        {
            return symbol;
        }

        (*index) += step;
        symbol = (unsigned char*)(arr + (*index));
    }

    return symbol;
}

/*
void my_shellsort (Line *lines, int nlines, comparer_t *str_compare)
{
    assert (lines);
    assert (str_compare);

    Line temp = {};

    for (int gap = nlines/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < nlines; i++)
        {
            for (int j = i - gap; j >= 0 && str_compare ((const void *)(lines + j),(const void *) (lines + (j + gap))) > 0; j -= gap)
            {
                temp = lines[j];
                lines[j] = lines[j + gap];
                lines[j + gap] = temp;
            }
        }
    }
}*/

void my_shellsort (void *ptr, size_t count, size_t size, comparer_t *str_compare)
{
    assert (ptr);
    assert (str_compare);

    for (int gap = count/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < count; i++)
        {
            for (int j = i - gap; j >= 0 && str_compare ((const void *)(ptr + size*j),(const void *) (ptr + size*(j + gap))) > 0; j -= gap)
            {
                void *ptr1 = ptr + size*j;
                void *ptr2 = ptr + size*(j + gap);

                swap (ptr1, ptr2, size);
            }
        }
    }
}
void swap (void *ptr1, void *ptr2, size_t size)
{
    void *temp = calloc (1, size);

    memcpy (temp, ptr1, size);
    memcpy (ptr1, ptr2, size);
    memcpy (ptr2, temp, size);

    free (temp);
}

