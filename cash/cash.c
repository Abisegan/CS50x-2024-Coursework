#include <cs50.h>
#include <stdio.h>
int main (void)
{
    // prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("change owed: ");
    }
    while(cents < 0);
}
int calculate_quarters(int)
{
    // calculate how many quarters you should give customer
    // subtract the value of the quarters from cent
}
    // calculate how many dimes you should give customer
    // subtract the value of the dimes from cent

    // calculate how many nickels you should give customer
    // subtract the value of the nickels from cent

    //calculate how many pennies you shold give customer
    //subtract the value of the pennies from cent

    // summ the number of quarters, dimes, nickels, pennies used
    // print the sum

