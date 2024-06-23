# include <cs50.h>
# include <stdio.h>
# include <ctype.h>
string tolower(string key)
bool alpha_check(string key)
bool repeat_check(string key)

int main(int argc, string argv[])
{
    // get key
    if(argc != 2)
    {
        printf("Usage: ./substitution KEY");
    }
    string key1 = argv[1]
    string key2 = tolower(key1)
    // validate key
    bool alpha = alpa_check(key);
    bool repeat = repeat_check(key);
    if (strlen(key) != 26)
    {
         printf("key must contain 26 characters");
        return 1;
    }
    if (alpha != TRUE)
    {
        printf("key must only contain alphabatic characters");
        return 1;
    }
    if(repeat == TRUE)
    {
         printf("key must not contain repeated characters");
                return 1;
    }

    string key2 = tolower(key1)
    // get plain text
    // enciper
    // print cipher text
}
