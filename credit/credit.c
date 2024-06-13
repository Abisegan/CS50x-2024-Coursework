#include <cs50.h>
#include <stdio.h>
int check_digits(int number);

int main(void)
{
    // prompt the user for card number
    int number;
    number = get_int("Number: ");


    //check the validity of card
    int digits= check_digits(number);


    //check which card is it
    int checksum = 0;
    int n = 5;
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
    }
    while (number <= 0);
    printf("%i\n",n%2);
}
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
    return digits;
}

