#include <cs50.h>
#include <stdio.h>
#include <math.h>

//if first number is 4 && checksum is correct && length is 13 or 16 -> then it's a visa
//else if first number is 3 and second number is 4 or 7 -> if true then it's AMEX
//else invalid
//if
int getDigit(long num, int position);
int get_length(long num);
int get_sum(int current_sum, int current);
int main(void)
{
    do
    {
        //get number from user
        long card_number = get_long("card number: ");
        //get the digits on the first and second positions of the card number
        int position1 = getDigit(card_number, 0);
        int position2 = getDigit(card_number, 1);
        //check length and store its value
        int length = get_length(card_number);

        //if length is not 13,15, or 16, then then number is invalid
        if (!(length == 13 || length == 15 || length == 16))
        {
            printf("INVALID\n");
        }
        else
        {
            int sum_product_digits = 2;
            int sum_other_digits = 2;
            int j = length - 1;
            int k = length - 2;
            for (int i = length - 1; i >= 0; i--)
            {
                int sum_other_digits = get_sum(sum_other_digits, getDigit(card_number, k));
                printf("%i... %i \n", sum_other_digits, 2 * getDigit(card_number, k));

                j = j - 2;
                k = k - 2;
            }
        }
        // printf("%i\n", digit1);

    } while (false);
}

int getDigit(long num, int position)
{
    return (num / (long)pow(10, floor(log10(num)) - position)) % 10;
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

int get_sum(int current_sum, int current)
{
    current_sum += current;
    return current_sum;
}