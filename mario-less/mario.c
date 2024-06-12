#include <cs50.h>
#include <stdio.h>
void print_row(int bricks);
int main(void)
{
    // prompt the user for the pyrmid's hight
    int n;
    do
    {
        n = get_int("Hight: ");
    }
    while(n < 1);
     // print the pyrmid of the hight
     for (int i = 0; i < n; i++)
     {
        // print row of bricks
        print_row(i + 1);
     }
}
void print_row(int bricks)
{
    // print row of bricks
}
