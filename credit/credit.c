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
    int x = 100;
    for (int i = 0; i <= digits/2; i++)
    {
        checksum = checksum + number % x;

    }
    printf("%i\n",number % x);
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

