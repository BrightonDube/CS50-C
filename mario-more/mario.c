#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 1;
    int final_height = 0;
    int spaces;
    const int gap = 2;
    do
    {
        //prompt user for final_height and save it
        while (!(final_height >= 1 && final_height <= 8))
            final_height = get_int("Pyramid final_height: ");
        //calculate how many spaces will be printed
        spaces = final_height - height;
        printf("%.*s", spaces, "        ");
        printf("%.*s", height, "#########");
        printf("%.*s", gap, "   ");
        printf("%.*s", height, "#########");
        printf("\n");
        height++;

    } while (height <= final_height);
}