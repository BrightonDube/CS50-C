#include <stdio.h>
#include <cs50.h>
float discount(float regular, int discount_factor);

int main(void)
{
    int discount_percentage = get_int("Discount percentage? ");
    float regular_price = get_float("Regular price? $");

    float discounted_price = discount(regular_price, discount_percentage);

    printf("Discounted Price: $%.2f !!!\n", discounted_price);
}

float discount(float regular, int discount_factor)
{
    return regular - (regular * discount_factor / 100);
}