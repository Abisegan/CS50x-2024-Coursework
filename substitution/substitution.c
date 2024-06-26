# include <cs50.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
bool alpha_check(string key2);
bool repeat_check(string key2);
int main(int argc, string argv[])
{
    // get key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }


    string key1 = argv[1];
    char key[26];
    for (int x = 0; x < 26; x++)
    {

        key[x] = tolower(key1[x]);


    }
    printf("%s\n",key);
     // validate key
    string key2 = key;
    bool alpha = alpha_check(key2);
    bool repeat = repeat_check(key2);

    if (strlen(key1) != 26)
    {
         printf("key must contain 26 characters.\n");
        return 1;
    }
    if (alpha == false)
    {
        printf("key must only contain alphabatic characters.\n");
        return 1;
    }
    if(repeat == false)
    {
        printf("key must not contain repeated characters.\n");
        return 1;
    }
    // get plain text
    string plaintext = get_string("plaintext: ");
    // enciper
    char ciphertext[strlen(plaintext)];
    int c = strlen(plaintext);
    printf("%i\n",c);
    for(int i = 0,len = strlen(plaintext); i < len; i++)
    {
        if (islower(plaintext[i]))
        {
            ciphertext[i] = key2[plaintext[i] - 'a'];
        }
        else if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(key2[plaintext[i] - 'A']);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    // print cipher text
    printf("ciphertext: %s\n",ciphertext);
}
 bool repeat_check(string key2)
 {
    bool n;
    for (int i = 0;  i < 26; i++)
    {
        for ( int j = i + 1;  j < 26; j++)
        {
            if (key2[i] == key2[j])
            {
                n = false;
                i = 26;
                j = 25;
            }
            else
            {
                n = true;
            }
        }

    }
    return n;
 }
bool alpha_check(string key2)
{
    bool n;
    for ( int i = 0; i < 26; i++)
    {
        if (isalpha(key2[i]))
        {
            n = true;
        }
        else
        {
            n = false;
            i = 26;
        }
    }
    return n;
}

