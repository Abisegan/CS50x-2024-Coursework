# include <cs50.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
bool alpha_check(string key2);
bool repeat_check(string key2);


int main(int argc, string argv[])
{
    // get key



    string key1 = argv[1];
    string key[1];
    for (int x = 0; x < 26; x++)
    {
        key3 = key[0];
        key3[x] = tolower(key1[x]);


    }

    string key2 = key[0];
    bool alpha = alpha_check(key2);
    bool repeat = repeat_check(key2);
    // validate key
    printf("%s\n",key2);
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
    // enciper
    // print cipher text
}
 bool repeat_check(string key2)
 {
    bool n;
    for (int i = 0;  i < 26; i++)
    {
        for ( int j = 0;  j < 26; j++)
        {
            if (key2[i] == key2[j])
            {
                n = false;
                i = 27;
                j = 27;
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
            i = 27;
        }
    }
    return n;
}

