#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // prompt the user for card number
    int number;
    number = get_int("Number: ");


    //check the validity of card
int check_digits(int number)
{
    int n = 0;
    int digits=0;

    int x = 10;
    do
    {

        n = number / x;
        digits++;
        x = x * 10;

    }
    while(n >=1);
}
    
    //check which card is it
}
