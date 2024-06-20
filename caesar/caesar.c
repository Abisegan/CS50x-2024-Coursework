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
        for (int i = 0, len = strlen(key); i < len; i++)
            if (isdigit(key[i]))
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
        return 1;
    }
    // get plaintext
    // encipher
    // print ciphertext


}
