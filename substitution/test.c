# include <cs50.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

int main(int argc,string argv[])
{
    string key2 = argv[1];
    int n = 0;
    int i =  6;
    while (i > 5)
    {
        if (isalpha(key2[i]))
        {
            n = 0;
            i--;
        }
        else
        {
            n = 1;
        }

    }
    printf("%i",n);

}
