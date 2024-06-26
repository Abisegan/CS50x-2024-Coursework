# include <cs50.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

int main(int argc,string argv[])
{
    string key2 = argv[1];
   string plaintext = get_string("plaintext: ");
    // enciper
    string ciphertext[1];
    for(int i = 0,len = strlen(plaintext); i < len; i++)
    {
        ciphertext[0][i] = key2[plaintext[i] - 'a'];
    }
    printf("%s",ciphertext[0]);
    // print cipher text
    printf("%i",n);

}
