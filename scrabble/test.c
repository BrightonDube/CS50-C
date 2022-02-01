#include <stdio.h>
#include <ctype.h>

int main(void)
{

    int test[] = {9, 1, 3, 4, 5, 7, 7, 8, 9};

    for (int i = 0; i <= sizeof(test) / sizeof(test[0]); i++)
    {
        if (i == 6)
            printf("%i", i);
    }
}