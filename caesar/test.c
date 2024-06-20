#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char c = 0;
    char p = 'a';
    int n = 1;

    if (isalpha(p))
    {
        c = ((p -'a')+ n) % 26;
    }
    printf("%c\n",c);
}
