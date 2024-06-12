#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // prompting for pyrmid's hight
    int n = get_hight()

    //printing pyrmid
    for (int i = 0; i < n; i++)
    {
        print_row()
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
        
    }
}
