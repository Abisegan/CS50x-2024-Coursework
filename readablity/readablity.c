#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int count_sentences(string text);
int count_words(string text);
int count_letters(string text);
float Index(int letters,int words,int sentences);
int main(void)
{
    // prompt the user for some text
    string text = get_string("Text: ");
    // count the number of letters, words and the sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // compute the colemen-liau index
    float index = Index(letters, words, sentences);

    // print the grade level
    int grade_level = round(index);
    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 1 && grade_level <= 16)
    {
        printf("Grade %i\n",grade_level);
    }
    else
    {
        printf("Grade 16+\n");
    }
    printf("%i\n",grade_level);
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
        if (text[i] != 39)
        {
            n++;
        }
    }
    return n;
}
float Index(int letters,int words,int sentences)
{
    float L = ((float)letters / (float)words) * 100.0;
    float S = ((float)sentences / (float)words) * 100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}
