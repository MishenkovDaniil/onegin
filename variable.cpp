#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int compare_two_backwards (char *ptr1, char *ptr2);

    /*Text orig = {};
    split_text(&orig, buf);

    Text sorted = {};
    split_text()

    sort(sorted)

    print_text();

*/


    // free_text() буфер


// Открой прототип qsort
// Сделай такой же
// Моджешь написать свой swap:
// Сначала, чтобы работало
// Потом:
// 1. Меняешь по 8 байт
// 2. Меняешь по 4 байт
// 3. Меняешь по 2 байт
// 4. Меняешь по 1 байт


// split text array of lines
// split_text(Text text, buf)

// calloc lines

//void print_text(const Text *text)
//{}


// Можно намного меньше universal_sort

int main ()
{
    /*
    const int SIZE = 5;
    char *arr[SIZE] = {"", "5", "-6 0", "-1 1 2", "0 0 3 1"};
    //arr[0] = "";
    //arr[1] = "5";
    //arr[2] = "-6 0";
    //arr[3] = "-1 1 2";
    //arr[4] = "0 0 3 1";

    for (int i = 0; i < SIZE; i++)
    {
        if (*(arr[i]) == '\0')
        {
            printf ("\n");
        }
        else
        {
            int j = 0;
            while (*(arr[i] + j))
            {
                char p = *(arr[i] + j);

                if (p == ' ')
                {
                    p = '\t';
                }
                if (p == '-')
                {
                    printf ("%c", p);
                }
                else
                {
                    printf ("%-4c", p);
                }

                j++;
            }
            printf ("\n");
        }
    }
    */
    unsigned char a = 'ё';
    unsigned char b = 'А';
    printf ("%d\n%d", a, b);

}

