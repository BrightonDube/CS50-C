#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	string name = get_string("What's your name? ");
	printf("Hello %s\n", name);
	string age = get_string("How old are you? ");
	printf("You are %s years old \n", age);
	puts("hello world");
	return EXIT_SUCCESS;//not necessary!!!
}
