#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// points assigned to each letter of the alphabet
int points[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int compute_score(string word);
int main(void)
{
    // prompt the user for two words
    string word1 = get_string("player: ");
    string word2 = get_string("player: ");

    // compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // print the winner
    if (score1 > score2)
    {
        printf("player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("player 2 wins!\n");

    }
    else
    {
        printf("tie!\n");
    }
}
int compute_score(string word)
{
    //keep track of score
    int score = 0;
    // compute and return score for word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += point[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += point[word[i] - 'a'];
        }

    }
    return score;
}
