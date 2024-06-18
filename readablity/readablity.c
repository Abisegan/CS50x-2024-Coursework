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
