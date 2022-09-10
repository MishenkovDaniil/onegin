#include "compare_str.h"

int compare_str (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = *(const char **) str1;
    const char *arr2 = *(const char **) str2;

    assert (arr1);
    assert (arr2);

    while ((!(isalnum (*arr1))) && (*arr1 != '\0'))//
    {
        arr1++;
    }
    while ((!(isalnum (*arr2))) && (*arr2 != '\0'))//
    {
        arr2++;
    }

    while ((*arr1++ == *arr2++) && (*arr1 != '\0') && (*arr2 != '\0'));//
        ;

    return *--arr1 - *--arr2;
}

int compare_str_backwards (const void *str1, const void *str2)
{
    assert (str1);
    assert (str2);

    const char *arr1 = *(const char **) str1;
    const char *arr2 = *(const char **) str2;

    assert (arr1);
    assert (arr2);

    int a = strlen (arr1);
    int b = strlen (arr2);

    while (arr1[--a] == arr2[--b])
        ;

    return arr1[a] - arr2[b];
}
