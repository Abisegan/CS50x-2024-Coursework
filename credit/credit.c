#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // prompt the user for card number
    int number;
    number = get_int("Number: ");


    //check the validity of card


    //check which card is it
    int checksum = 0;
    int n = 1;
    int x = 10;
    do
    {
        if (n % 2 == 0)
        {
            checksum = checksum + number % 10 * 2;
            n++;
        }
        else
        {
            checksum = checksum + number % 10;
            n++;
        }
        number = number - number % 10;

        number = number/10;

    }
    while (number <= 0);
    printf("%i\n",number);

}


