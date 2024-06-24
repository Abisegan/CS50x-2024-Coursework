# include <cs50.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
char alphabatic[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
bool alpha_check(string key2[]);
bool repeat_check(string key2[]);
string to_lower(string key1);

int main(int argc, string argv[])
{
    // get key
    if(argc != 2)
    {
        printf("Usage: ./substitution KEY");
    }

    string key1 = argv[1];
    char key2[] = to_lower(key1);
    bool alpha = alpha_check(key2);
    bool repeat = repeat_check(key2);
    // validate key

    if (strlen(key1) != 26)
    {
         printf("key must contain 26 characters");
        return 1;
    }
    if (alpha != true)
    {
        printf("key must only contain alphabatic characters");
        return 1;
    }
    if(repeat != true)
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
    for (int i = 0; i < 26; i++)
    {
        for ( int j = 0; j < 26; j++)
        {
            if (alphabatic[i] == key2[j])
            {
                n = false;
            }
            else
            {
                n = true;
            }
        }
    }
    return n;
 }
bool alpha_check(char key2)
{
    bool n;
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key2[i]))
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
char to_lower(string key1)
{
    char key2[25];
    for (int x = 0; x < 26; x++)
    {
        key2[x] = tolower(key1[x]);

    }
    return key2;
}
