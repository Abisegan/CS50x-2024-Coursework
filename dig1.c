#include <cs50.h>
#include <stdio.h>
int checksum(long number);
int sub_checksum(int number);


int main(void)
{
    // prompt the user for card number
    long number;
    number = get_long("Number: ");
    int k = checksum(number);

    printf("%i\n", k);

}
    //check the validity of card


    //check which card is it
int checksum(long number)
{
    int checksum = 0;
    int checksum1 = 0;
    int checksum2 = 0;
    int n = 1;
    int digit = 0;
    while (number > 0)
    {
        if (n % 2 == 0)
        {
            checksum1 = checksum1 + sub_checksum(number % 10 * 2);
            n++;
        }
        else
        {
            checksum2 = checksum2 + number % 10;
            n++;
        }
        number = number - number % 10;
        digit++;
        number = number/10;

    }
    checksum = checksum1 + checksum2;
    return checksum;
}


int sub_checksum(int number)
{

    int checksum = 0;
    while(number > 0)
    {
    checksum = checksum + number % 10 ;
    number = number - number % 10;
    number = number / 10;
    }
    return checksum;
}
