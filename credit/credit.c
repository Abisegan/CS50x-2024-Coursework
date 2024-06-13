#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // prompt the user for card number
    int number;
    number = get_int("Number: ");


    //check the validity of card
    int n = 0;
    int digit=0;

    int x = 10;
    while(digit >=0)
    {

        digit = number / x;
        n++;
        x = x * 10;

    }


    printf("%i", n);
    //check which card is it
}
