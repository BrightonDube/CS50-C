#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//ascii values of alphabet
int a_to_zee[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

int get_char_val(char a);
int compute_score(string word);
int index_of(int x);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    printf("%i %i\n", score1, score2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            score += get_char_val(word[i]);
        }
    }
    return score;
}
int index_of(int x)
{
    for (int i = 0; i <= sizeof(a_to_zee) / sizeof(a_to_zee[0]); i++)
    {
        if (a_to_zee[i] == x)
            return i;
    }
}
int get_char_val(char a)
{
    if (isupper(a))
    {
        a = tolower(a);
    }
    return POINTS[index_of(a)];
}