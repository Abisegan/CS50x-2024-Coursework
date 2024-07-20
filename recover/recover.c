#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc !== 2)
    {
        printf("usage: ./recover FILE\n");
        retuen 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card)
    // While there's still data left to read from the memory card
    // Create jpg from the data

}
