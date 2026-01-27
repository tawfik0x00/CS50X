#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score(string word);

int main(void)
{
    // first take the words of the user
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // determine the score of the words
    int score1 = score(word1);
    int score2 = score(word2);
    // determine the winner of the game
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
int score(string word)
{
    // first define the values of each letter in an array.
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    // second thing we determine the score
    int score = 0;
    int index;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // we need to get the index of each letter to get the score
        if (isalpha(word[i]))
        {
            index = (isupper(word[i])) ? word[i] - 65 : word[i] - 97;
            score += POINTS[index];
        }
    }

    return score;
}
