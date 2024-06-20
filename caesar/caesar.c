#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
bool only_digit(string key);
int main(int argc,string argv[])
{
    // get key
    string key;
    bool digit;
    if (argc == 1)
    {
        printf("usage:  ");
        return 1;
    }
    else
    {
        key = argv[1];
        digit = only_digit(key);
    }
    if ((argc == 2) && (digit == true))
    {
        printf("%s",key);
        return 0;
    }
    else
    {
        printf("usage:  ");
        return 1;
    }
    // get plaintext
    // encipher
    // print ciphertext


}
bool only_digit(string key)
{
    bool n = false;
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (isdigit(key[i]))
        {
            n = true;
        }
        else
        {
            n = false;
        }
    }
    return n;
}
