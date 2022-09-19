#include <stdio.h>
#include <stdlib.h>

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

// ������ �������� qsort
// ������ ����� ��
// ������� �������� ���� swap:
// �������, ����� ��������
// �����:
// 1. ������� �� 8 ����
// 2. ������� �� 4 ����
// 3. ������� �� 2 ����
// 4. ������� �� 1 ����
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
            for (int j = i - gap; j >= 0 && str_compare ((const void *)(ptr + j),(const void *) (ptr + (j + gap))) > 0; j -= gap)
            {
                swap (ptr + j, ptr + j + gap);
            }
        }
    }
}
void swap (void *ptr1, void *ptr2)
{
    void *temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}
