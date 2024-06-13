#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // prompt the user for card number
    int number;
    number = get_int("Number: ");


    //check the validity of card
    int checksum = 0;
    int digit=0;

    int x = 10;
    do
    {

        checksum = checksum + number % x;
        x*10;
        digit = 
    }

    while(digit >=0);
    printf("%i", checksum);
    //check which card is it
}
