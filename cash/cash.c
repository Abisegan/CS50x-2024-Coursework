#include <cs50.h>
#include <stdio.h>
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int main (void)
{
    // prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("change owed: ");
    }
    while(cents < 0);
    // caiculate how many quarters you should give customer
    int quarters = calculate_quarters(cents);
    // subtract the value of quarters from cent
    cent = cent - (quarters * 25);

    // calculate how many dimes you should give customer
    int dimes = calculate_dimes(cents);
    // subtract the value of the dimes from cent
    cent = cent - (dimes * 10);
}
int calculate_quarters(int cents)
{
    c
    int quarters = 0;
    while(cents >= 0)
    {
        querters++;
        cents = cents - 25;
    }
    return quarters;

}
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cent >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;

}
    // calculate how many nickels you should give customer
    // subtract the value of the nickels from cent

    //calculate how many pennies you shold give customer
    //subtract the value of the pennies from cent

    // summ the number of quarters, dimes, nickels, pennies used
    // print the sum

