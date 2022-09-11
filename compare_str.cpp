#include "compare_str.h"

int compare_str (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = *(const char **) str1;
    const char *arr2 = *(const char **) str2;

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

    const char *arr1 = *(const char **) str1;
    const char *arr2 = *(const char **) str2;

    assert (arr1);
    assert (arr2);

    int a = strlen (arr1) - 1;
    int b = strlen (arr2) - 1;

    while (a > 0 && b > 0)
    {
        while (!(isalnum (arr1[a])) && a > 0)
        {
            a--;
        }
        while (!(isalnum (arr2[b])) && b > 0)
        {
            b--;
        }

        if (arr1[a] == arr2[b] && a > 0 && b > 0)
        {
            a--;
            b--;
        }
        else
        {
            return arr1[a] - arr2[b];
        }
    }

    return arr1[a] - arr2[b];
}
