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
    int n = 10;
    int x = 10 * n;
    while(digit >=0)
    {

        checksum = checksum + number % x;
        n * 10;
        
    }

    printf("%i", checksum);
    //check which card is it
}
