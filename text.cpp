#include <stdio.h>

#include "text.h"
#include "sort.h"

int compare_str (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = ((struct Line *)str1)->start;
    const char *arr2 = ((struct Line *)str2)->start;

    assert (arr1);
    assert (arr2);

    int len1 = ((struct Line *)str1)->len;
    int len2 = ((struct Line *)str2)->len;

    int step = 1;

    return universal_compare(arr1, len1, arr2, len2, step);
}

int compare_str_backwards (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = ((struct Line *)str1)->start;
    const char *arr2 = ((struct Line *)str2)->start;

    assert (arr1);
    assert (arr2);

    int len1 = ((struct Line *)str1)->len;
    int len2 = ((struct Line *)str2)->len;

    int step = -1;

    return universal_compare(arr1 + len1, len1, arr2 + len2, len2, step);
}

int universal_compare (const char *arr1, int strlen_1, const char *arr2, int strlen_2, const int step)
{
    assert (arr1);
    assert (arr2);

    int arr1_index = 0;
    int arr2_index = 0;

    while (arr1_index < strlen_1 && arr2_index < strlen_2)
    {
        unsigned char *alnum1 = skip_extra_symbols (arr1, &arr1_index, step, strlen_1);
        unsigned char *alnum2 = skip_extra_symbols (arr2, &arr2_index, step, strlen_2);

        if (*alnum1 == *alnum2)
        {
            arr1_index += step;
            arr2_index += step;
        }
        else
        {
            return (*alnum1 - *alnum2);
        }
    }

    return *(arr1 + arr1_index - arr2_index);
}
