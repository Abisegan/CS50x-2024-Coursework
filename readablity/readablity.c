#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int count_sentences(string text);
int count_words(string text);
int count_letters(string text);
int main(void)
{
    // prompt the user for some text
    string text = get_string("Text: ");
    // count the number of letters, words and the sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // compute the colemen-liau index
    int L = (letters / words) * 100;
    int S = (sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // print the grade level
    int grade_level = round(index);


    printf("%f\n",index);
    printf("%i\n",letters);
    printf("%i\n",words);
    printf("%i\n",sentences);
}
int count_letters(string text)
{
    int n = 0;
    // return the number of letters in the text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
      if (isalpha(text[i]))
        {
            n++;
        }
    }
    return n;
}
int count_words(string text)
{
    int n = 0;
    // return the number of words in the text
    for (int i = 0, len = strlen(text); i < len; i++)
    if (isspace(text[i]))
    {
        n++;
    }
    return n + 1;

}
int count_sentences(string text)
{
     // return the number of sentences in the text
    int n = 0;
    for (int i = 0,len = strlen(text); i < len; i++)
    if (ispunct(text[i]))
    {
        n++;
    }
    return n;
}
