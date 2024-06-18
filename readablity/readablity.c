#include <cs50.h>
#include <stdio.h>




int main(void)
{
    // prompt the user for some text
    string text = get_string("Text: ");
    // count the number of letters, words and the sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // compute the colemen-liau index
    // print the grade level


}
int count_letters(string text)
{
    // return the number of letters in the text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(text[i] == isspace)
    }

}
int count_words(string text)
{
    // return the number of words in the text

}
int count_sentences(string text)
{
    // return the number of sentences in the text
}
