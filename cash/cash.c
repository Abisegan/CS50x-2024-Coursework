#include <cs50.h>
#include <stdio.h>
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
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
    cents = cents - (quarters * 25);

    // calculate how many dimes you should give customer
    int dimes = calculate_dimes(cents);
    // subtract the value of the dimes from cent
    cents = cents - (dimes * 10);

    // calculate how many nickels you should give customer
    int nickels = calculate_nickels(cents);
    // subtract the value of the nickels from cent
    cents = cents - (nickels * 5);

     //calculate how many pennies you shold give customer
    int pennies = calculate_pennies(cents);
    //subtract the value of the pennies from cent
    cents = cents - (pennies * 1);

    // summ the number of quarters, dimes, nickels, pennies used
    int sum = quarters + dimes + nickels + pennies;

     // print the sum
    printf("%i", sum);
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
int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}
int calculate_pennies(int cents)
{
    int pennies = 0;
    while(cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}








