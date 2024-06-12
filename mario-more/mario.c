#include <cs50.h>
#include <stdio.h>
void print_row(int spaces, int bricks);
int get_hight(void;)
int main(void)
{
    // prompt the user for pyrmid's hight
    int n = get_hight();

    //printing pyrmid of hight
    for (int i = 0; i < n; i++)
    {
        // print row of bricks and spaces
        print_row(n - i, i + 1);
    }

}
void print_row(int spaces , int bricks)
{
    // print spaces
    for (int j = 1; j < spaces; j++)
    {
        printf(" ");
    }
    // print bricks
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
int get_hight(void)
{
    int n;
    do
    {
        n = get_int("Hig)
    }
}
