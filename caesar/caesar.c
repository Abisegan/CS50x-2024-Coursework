#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
bool only_digit(string key);
char rotate(char p, int n);
int main(int argc,string argv[])
{
    // get key
    string key1;
    bool digit;
    if (argc == 1)
    {
        printf("usage:  ");
        return 1;
    }
    else
    {
        key1 = argv[1];
        digit = only_digit(key1);
    }
    if ((argc == 2) && (digit == true))
    {
        return 0;
    }
    else
    {
        printf("usage:  ");
        return 1;
    }
    int key2 = atoi(key1);
    char p = 'A';
    string text = get_string("plaintext:  ");
    char v = rotate( p, key2);
    printf("%c",v);
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
char rotate(char p, int n)
{
    char c;
    if (isalpha(p))
    {
        if (isupper(p))
        {
            c = (('p' - 'A') + n) % 26;
        }
        else
        {
            c = (('p' - 'a') + n) % 26;
        }
    }
    else
    {
        c = p;
    }
    return c;
}
