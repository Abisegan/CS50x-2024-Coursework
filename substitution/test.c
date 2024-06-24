# include <cs50.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

int main(int argc,string argv[])
{

    key1 = argv[1];
    string key[1];
    for (int x = 0; x < 25; x++)
    {
        key[0][x] = tolower(key1[x]);

    }
    printf("%s",key[0]);

}
