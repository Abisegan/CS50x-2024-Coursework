# include <cs50.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

int main(int argc,string argv[])
{
    string key2 = argv[1];
    int n = 0;
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key2[i]))
        {
            n = 0;
        }
        else
        {
            n = 1;
            i = 27;
        }

    }
    printf("%i",n);

}
