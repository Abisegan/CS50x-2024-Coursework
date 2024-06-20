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

        printf("%s",key);
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
      for (int i = 0, len = strlen(key); i < len; i++)
        {
            if (isdigit(key[i]))
                {

                    return 0;
                }
        }
}
