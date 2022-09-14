#include "compare_str.h"
#include <stdio.h>
#include "consts.h"
int compare_str (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = ((struct Strings *)str1)->p;
    const char *arr2 = ((struct Strings *)str2)->p;

    assert (arr1);
    assert (arr2);

    int i, j;
    i = j = 0;

    while ((*(arr1 + i) != '\0') && (*(arr2 + j) != '\0'))
    {
        if ((isalnum (*(arr1 + i))) && (isalnum (*(arr2 + j))))
        {
            if ((*(arr1 + i)) == (*(arr2 + j)))
            {
                i++;
                j++;
            }
            else
            {
               return *(arr1 + i) - *(arr2 + j);
            }
        }
        else
        {
            if (!(isalnum (*(arr1 + i))))
            {
                i++;
            }
            if (!(isalnum (*(arr2 + j))))
            {
                j++;
            }
        }
    }

    return *(arr1 + i) - *(arr2 + j);
}

int compare_str_backwards (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = ((struct Strings *)str1)->p;
    const char *arr2 = ((struct Strings *)str2)->p;

    assert (arr1);
    assert (arr2);

    int a = ((struct Strings *)str1)->size;
    int b = ((struct Strings *)str2)->size;

    while (a > 0 && b > 0)
    {
        while (!(isalnum (arr1[a])) && arr1[a] != 'ÿ' && a > 0)
        {
            a--;
        }
        while (!(isalnum (arr2[b])) && arr2[b] != 'ÿ' && b > 0)
        {
            b--;
        }

        unsigned char ascii_cod1 = arr1[a];
        unsigned char ascii_cod2 = arr2[b];

        if (ascii_cod1 == ascii_cod2 && a > 0 && b > 0)
        {
            a--;
            b--;
        }
        else
        {
            return ascii_cod1 - ascii_cod2;
        }
    }

    return arr1[a] - arr2[b];
}
