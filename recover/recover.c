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
    if (card == NULL)
    {
        return 1;
    }
    // Create a buffer for a block of data
    uint8_t buffer[512];
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && 0xe0 < buffer[3] > 0xef)
        {
            FILE *card1 = fopen(001)
            fwrite(buffer, 1, 512, card1);
        }
    }
    // Create jpg from the data

}
