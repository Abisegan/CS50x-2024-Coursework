#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int color =  round((image[i][j].rgbtred + image[i][j].rgbtgreen + image[i][j].rgbtblue) / 3.0);
            image[i][j].rgbtred = color;
            image[i][j].rgbtgreen = color;
            image[i][j].rgbtblue = color;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = 0.393 * image[i][j].rgbtred
            int sepiaGreen = 0.349 * image[i][j].rgbtgreen
            int sepiaBlue = 0.272 * image[i][j].rgbtred
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
