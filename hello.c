// #include <ctype.h>
#include <cs50.h>
#include <stdio.h>
// #include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//ascii values of alphabet
//char a_to_zee[] = {"abcdefghijklmnopqrstuvxyz"};
int a_to_zee[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
int get_char_val(char a);
int index_of(int x);
int main(void)
{
	// string name = get_string("What's your name? ");
	// printf("Hello %s\n", name);
	// get_char_val('t');
	printf("%i \n", get_char_val('q'));
}

int get_char_val(char a)
{	
	return POINTS[index_of(a)];
}
int index_of(int x)
{
	for (int i = 0; i <= sizeof(a_to_zee) / sizeof(a_to_zee[0]); i++)
	{
		if (a_to_zee[i] == x)
			return i;
	}
}