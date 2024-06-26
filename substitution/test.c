# include <cs50.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

int main(int argc,string argv[])
{
    string key2 = argv[1];
   string plaintext = get_string("plaintext: ");
    // enciper
    char ciphertext[3];
    for(int i = 0,len = strlen(plaintext); i < len; i++)
    {
        ciphertext[i] = key2[plaintext[i] - 'a'];
    }
    printf("%s",ciphertext[0]);
    // print cipher text


}
