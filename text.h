#ifndef TEXT_H
#define TEXT_H

#include <ctype.h>
#include <assert.h>
#include <string.h>

const char ONEGIN[] = "Eugine Onegin.txt";
const char DST[]    = "new onegin.txt";

typedef int comparer_t (const void *str1, const void *str2);

struct Line
{
    const char *start = nullptr;
    int len = 0;
};

int compare_str (const void *str1, const void *str2);
int compare_str_backwards (const void *str1, const void *str2);
int universal_compare (const char *arr1, int strlen_1, const char *arr2, int strlen_2, const int step);

#endif /* TEXT_H */
