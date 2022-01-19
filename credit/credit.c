#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_digit(long num, int position);
int get_length(long num);
int get_sum(int current_sum, int current);

int main(void)
{
    do
    {
        //get number from user
        long card_number = get_long("card number: ");
        //get the digits on the first and second positions of the card number
        int position1 = get_digit(card_number, 0);
        int position2 = get_digit(card_number, 1);
        //check length and store its value
        int length = get_length(card_number);

        //if length is not 13,15, or 16, then then number is invalid
        if (!(length == 13 || length == 15 || length == 16))
        {
            printf("INVALID\n");
        }
        else
        {
            //implement checksum
            int final_total;
            int sum_product_digits = 0;
            int sum_other_digits = 0;
            int running_product;
            int j = length - 1;
            int k = length - 2;
            for (int i = 8; i >= 0; i--)
            {
                //sum up the digits that are not multiplied by 2
                sum_other_digits = get_sum(sum_other_digits, get_digit(card_number, j));
                //sum up the product digits (i.e. all the individual digits that make up the products of 2)
                running_product = 2 * get_digit(card_number, k);
                if (get_length(running_product) > 1)
                {
                    //this takes care of cases where the product has 2 digits
                    running_product = get_digit(running_product, 0) + get_digit(running_product, 1);
                }
                sum_product_digits = get_sum(sum_product_digits, running_product);
                j = j - 2;
                k = k - 2;
            }

            final_total = sum_product_digits + sum_other_digits;
            bool result;
            if (get_length(final_total > 1))
            {
                if (get_digit(final_total, 1) == 0)
                    result = true;
                else
                    result = false;
            }

            //if firt number is not 3, 4, or 5, then number is invalid
            if (!(position1 == 3 || position1 == 4 || position1 == 5))
            {
                printf("INVALID\n");
            }
            else
            {

                //if first number is 4 && checksum is correct && length is 13 or 16 -> then it's a visa 4003600000000014
                if (position1 == 4 && result && (length == 13 || length == 16))
                {
                    printf("VISA\n");
                }
                //else if first number is 3 and second number is 4 or 7 and checksum is correct then it's AMEX e.g 378282246310005
                else if (position1 == 3 && (position2 == 4 || position2 == 7) && result && length == 15)
                {
                    printf("AMEX\n");
                }
                //else if checksum is correct and first number is 5 and second number is 1, 2, 3, 4, or 5  and length is 16 then it's MASTERCARD e.g. 5105105105105100

                else if (result && position1 == 5 && (position2 == 1 || position2 == 2 || position2 == 3 || position2 == 4 || position2 == 5) && length == 16)
                {
                    printf("MASTERCARD\n");
                }
                //else invalid
                else
                {
                    printf("INVALID\n");
                }
            }
        }

    } while (false);
}

int get_digit(long num, int position)
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
