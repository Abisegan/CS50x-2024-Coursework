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
    printf("%i\n",digits);



    //check which card is it
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
    checksum = 0;
    for (int i= 0;i = digits; i++)
    {
        checksum = checksum + number%10 * 2
    }


}
