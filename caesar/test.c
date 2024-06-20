#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char c ='s';
    char p = '7';
    int n = 2;

    if (isalpha(p))
    {
        printf("%c\n",c);
        if (isupper(p))
        {
            c = ((p - 'A') + n) % 26;
        }
        else
        {
            c = ((p - 'a') + n) % 26;
        }
    }
    else
    {
        c = p;
    }
    printf("%c\n",c);
}
