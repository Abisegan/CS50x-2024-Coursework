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
    do
    {

        digit = number / x;
        n++;
        x = x * 10;

    }
    while(digit >=1);

    printf("%i\n", n);
    //check which card is it
}
