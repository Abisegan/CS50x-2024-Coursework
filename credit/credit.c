#include <cs50.h>
#include <stdio.h>
int check_digits(int number);
int validity_check(int number,int digits);
int main(void)
{
    // prompt the user for card number
    int number;
    number = get_int("Number: ");


    //check the validity of card
    int digits= check_digits(number);


    //check which card is it
    checksum = 0;
    for (int i = 0; i <= digits/2; i++)
    {
        checksum = checksum + number
    }
    printf("%i\n",checksum);
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
int validity_check(int number,int digits)
{

    return checksum;

}
