#ifndef CONSTS_H
#define CONSTS_H

const char ONEGIN[] = "Eugine Onegin.txt";
const char DST[]    = "new onegin.txt";

typedef int str_compare_t (const void *str1, const void *str2);

struct Strings
{
    char *string = nullptr;
    int number = 0;
    int size   = 0;
};

#endif /* CONSTS_H */
