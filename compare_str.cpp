#include "compare_str.h"
#include <stdio.h>

#include "consts.h"

unsigned char skip_extra_symbols (const char *arr, int *index, const int step)
{
    unsigned char symbol = 0;

    for (symbol = arr[(*index)]; !(isalnum (symbol)) && (*index) > 0; symbol = arr[(*index) += step])
        ;

    return symbol;
}

int my_shellsort (Strings *strings, int nlines, str_compare_t *str_compare)
{
    assert (strings);
    assert (str_compare);

    Strings temp = {};

    for (int gap = nlines/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < nlines; i++)
        {
            for (int j = i - gap; j >= 0 && str_compare ((const void *)(strings + j),(const void *) (strings + (j + gap))) > 0; j -= gap)
            {
                temp = strings[j];
                strings[j] = strings[j + gap];
                strings[j + gap] = temp;
            }
        }
    }

    return 0;
}

/*int compare_str (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = ((struct Strings *)str1)->p;
    const char *arr2 = ((struct Strings *)str2)->p;

    assert (arr1);
    assert (arr2);

    int arr1_index = 0;
    int arr2_index = 0;

    while ((*(arr1 + arr1_index) != '\0') && (*(arr2 + arr2_index) != '\0'))
    {
        if ((isalnum (*(arr1 + arr1_index))) && (isalnum (*(arr2 + arr2_index))))
        {
            if ((*(arr1 + arr1_index)) == (*(arr2 + arr2_index)))
            {
                arr1_index++;
                arr2_index++;
            }
            else
            {
               return *(arr1 + arr1_index) - *(arr2 + arr2_index);
            }
        }
        else
        {
            if (!(isalnum (*(arr1 + arr1_index))))
            {
                arr1_index++;
            }
            if (!(isalnum (*(arr2 + arr2_index))))
            {
                arr2_index++;
            }
        }
    }

    return *(arr1 + arr1_index) - *(arr2 + arr2_index);
}

int compare_str_backwards (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = ((struct Strings *)str1)->p;
    const char *arr2 = ((struct Strings *)str2)->p;

    assert (arr1);
    assert (arr2);

    int arr1_index = ((struct Strings *)str1)->size;
    int arr2_index = ((struct Strings *)str2)->size;
    //printf ("%d\t", arr1_index);
    //printf ("%d\n", arr2_index);
    int step = -1;

    while (arr1_index > 0 && arr2_index > 0)
    {
        unsigned char alnum1 = skip_extra_symbols (arr1, &arr1_index, step);
        unsigned char alnum2 = skip_extra_symbols (arr2, &arr2_index, step);

        if (alnum1 == alnum2 && arr1_index > 0 && arr2_index > 0)
        {
            arr1_index--;
            arr2_index--;
        }
        else
        {
            return alnum1 - alnum2;
        }
    }

    return arr1[arr1_index] - arr2[arr2_index];
}*/

int compare_str (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = ((struct Strings *)str1)->string;
    const char *arr2 = ((struct Strings *)str2)->string;

    assert (arr1);
    assert (arr2);

    int len1 = ((struct Strings *)str1)->size;
    int len2 = ((struct Strings *)str2)->size;

    int step = 1;

    return uni_compare(arr1, len1, arr2, len2, step);
}

int compare_str_backwards (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = ((struct Strings *)str1)->string;
    const char *arr2 = ((struct Strings *)str2)->string;

    assert (arr1);
    assert (arr2);

    int len1 = ((struct Strings *)str1)->size;
    int len2 = ((struct Strings *)str2)->size;

    int step = -1;

    return uni_compare(arr1+len1, len1, arr2+len2, len2, step);
}

int uni_compare (const char *arr1, int strlen_1, const char *arr2, int strlen_2, const int step)
{
    int arr1_index = 0;
    int arr2_index = 0;

    while (arr1_index < strlen_1 && arr2_index < strlen_2)
        {
        unsigned char alnum1 = skip_extra_symbols (arr1, &arr1_index, step);
        unsigned char alnum2 = skip_extra_symbols (arr2, &arr2_index, step);


        if (alnum1 == alnum2)
        {
            arr1_index += step;
            arr2_index += step;
        }
        else
        {
            return alnum1 - alnum2;
        }
    }

    return arr1[arr1_index] - arr2[arr2_index];
}

