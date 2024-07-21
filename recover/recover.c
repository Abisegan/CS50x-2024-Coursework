#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("usage: ./recover FILE\n");
        return 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // Create a buffer for a block of data
    uint8_t buffer[512];
    // While there's still data left to read from the memory card
    char name[8];
    int counter = 0;
    FILE *img = NULL;
    while (fread(buffer, 1, 512, card) == 512)
    {
         // Create jpg from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter == 0)
            {
                sprintf(name, "%03i.jpg", counter);
                img = fopen(name, "w");
                fwrite(buffer, 1, 512, img);
                counter++;
            }
            else
            {
                fclose(img);
                sprintf(name, "%03i.jpg", counter);
                img = fopen(name, "w");
                fwrite(buffer, 1, 512, img);
                counter++;
            }
        }
        else
        {
            if(counter != 0)
            {
                fwrite(buffer, 1, 512, img);
            }
        }
    }
    fclose(card);
    fclose(img);



}

