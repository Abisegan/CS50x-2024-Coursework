#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char c;
    char p = 'a';
    if (isalpha(p))
    {
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
    printf("%c",c);
}
