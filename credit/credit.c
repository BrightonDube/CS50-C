#include <cs50.h>
#include <stdio.h>
#include <math.h>

//else check the checksum()

//if first number is 4 && checksum is correct && length is 13 or 16 -> then it's a visa
//else if first number is 3 and second number is 4 or 7 -> if true then it's AMEX
//else invalid
//if
int getDigit(long num, int position)
{
    return (num / (int)pow(10, floor(log10(num)) - position)) % 10;
}
int get_length(long num);
int getdigit(long num, int n);
int main(void)
{
    do
    {
        //get number from user
        long card_number = get_long("card number: ");
        int digit = getDigit(card_number, 0);
        int digit1 = getDigit(card_number, 1);

        //check length and store its value
        int length = get_length(card_number);
        //if length is not 13,15, or 16, then then number is invalid
        if (!(length == 13 || length == 15 || length == 16))
        {
            printf("INVALID\n");
        }

        printf("%i\n%i\n%i\n", digit, digit1, get_length(card_number));

    } while (false);
}

int getdigit(long num, int n)
{
    long r;

    r = num / pow(10, n);

    r = r % 10;

    return r;
}

int get_length(long num)
{
    int counter = 0;
    while (num > 0)
    {
        num = num / 10;
        counter++;
    }
    return counter;
}