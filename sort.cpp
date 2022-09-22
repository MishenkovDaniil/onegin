#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
    assert (ptr1);
    assert (ptr2);

    size_t index_8 = 0;
    for (; index_8 < size / 8; index_8++)
    {
        long long temp = ((long long *)ptr1)[index_8];

        ((long long *)ptr1)[index_8] = ((long long *)ptr2)[index_8];
        ((long long *)ptr2)[index_8] = temp;
    }

    size_t index_4 = index_8 * 2;
    for (; index_4 < size / 4; index_4++)
    {
        long temp = ((long *)ptr1)[index_4];

        ((long *)ptr1)[index_4] = ((long *)ptr2)[index_4];
        ((long *)ptr2)[index_4] = temp;
    }

    size_t index_2 = index_4 * 2;
    for (; index_2 < size / 2; index_2++)
    {
        short temp = ((short *)ptr1)[index_2];

        ((short *)ptr1)[index_2] = ((short *)ptr2)[index_2];
        ((short *)ptr2)[index_2] = temp;
    }

    size_t index_1 = index_2 * 2;
    for (; index_1 < size; index_1++)
    {
        char temp = ((char *)ptr1)[index_1];

        ((char *)ptr1)[index_1] = ((char *)ptr2)[index_1];
        ((char *)ptr2)[index_1] = temp;
    }
}
