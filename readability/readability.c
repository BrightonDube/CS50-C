#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int get_grade(string text);
int cl_index(int letters, int sentences, int words);
int main(void)
{
    string paragraph = get_string("Text: ");
    int grade = get_grade(paragraph);
    if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+");
    }
    else
        printf("Grade %i\n", grade);
}

int get_grade(string text)
{
    int letters = 0;
    int sentences = 0;
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }
    //printf("%i letters \n %i words \n %i sentences \n", letters, words, sentences);
    return cl_index(letters, sentences, words);
}

int cl_index(int letters, int sentences, int words)
{
    double average_letters = ((float)letters / words) * 100;
    double average_words = ((float)sentences / words) * 100;
    int index = round(0.0588 * average_letters - 0.296 * average_words - 15.8);
    //printf("%f %f \n", average_letters, average_words);
    return index;
}