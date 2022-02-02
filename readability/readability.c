#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

int get_grade(string text);
int main(void)
{
    string paragraph = get_string("Text: ");
int grade = get_grade(paragraph);
printf("Grade %i", grade);
}

int get_grade(string text){
    int letters = 0;
    int sentences = 0;
    int words = 0;
   for (int i = 0; i < strlen(text); i++){
       if (isalpha(text[i]))
   }
}