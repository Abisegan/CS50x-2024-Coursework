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
        printf("Usage: ");
        return 1;
    }


    string key1 = argv[1];
    string key[1];
    for (int x = 0; x < 26; x++)
    {

        key[0][x] = tolower(key1[x]);


    }

    string key2 = key[0];
    bool alpha = alpha_check(key2);
    bool repeat = repeat_check(key2);
    // validate key

    if (strlen(key1) != 26)
    {
         printf("key must contain 26 characters");
        return 1;
    }
    if (alpha == false)
    {
        printf("key must only contain alphabatic characters");
        return 1;
    }
    if(repeat == false)
    {
        printf("key must not contain repeated characters");
        return 1;
    }
    // get plain text
    string plaintext = get_string("plaintext: ");
    // enciper
    string ciphertext[1];
    for(int i = 0; i < 26; i++)
    {
        ciphertext[0][i] = key2[(plaintext[i] - 'a')];
    }
    printf("%s",ciphertext[0]);
    // print cipher text
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

