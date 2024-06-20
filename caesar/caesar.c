#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc,string argv[])
{
    // get key
    string key = argv[1];
    if (argc == 2)
    {
        if (isdigit(key[i]))
                for (int i = 0, len = strlen(key); i < len; i++)
                {
                    printf("%s",key);
                    return 0;
                }
                else
                {
                    printf("usage:  ");
                    return 1;
                }
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
