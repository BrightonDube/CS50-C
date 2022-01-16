#include <stdio.h>
void meow(int x);
void countdown(int n);

int main(void)
{
    const int n = 5;
    meow(4);
    countdown(n);
}

void meow(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("meow \n");
    }
}

void countdown(int n)
{
    while (n > 0)
    {
        printf("%i\n", n);
        n--;
    }
}