#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int color =  round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = color;
            image[i][j].rgbtGreen = color;
            image[i][j].rgbtBlue = color;
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
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (sepiaRed > 225)
            {
                image[i][j].rgbtRed = 225;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            if (sepiaGreen > 225)
            {
                image[i][j].rgbtGreen = 225;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 225)
            {
                image[i][j].rgbtBlue = 225;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int n;
    if (width % 2 == 0)
    {
        n = width/2;
    }
    else
    {
        n = (width - 1)/2;
    }
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < n; j++)
        {
            temp = image[i][j];


            image[i][j] = image[i][width - j];


            image[i][width - j] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            if (k == 0)
            {
                if (l == 0)
                {
                    image[k][l].rgbtRed = round((copy[k + 1][l].rgbtRed + copy[k][l + 1].rgbtRed + copy[k + 1][l + 1].rgbtRed)/3.0);
                    image[k][l].rgbtGreen = round((copy[k + 1][l].rgbtGreen + copy[k][l + 1].rgbtGreen + copy[k + 1][l + 1].rgbtGreen)/3.0);
                    image[k][l].rgbtBlue = round((copy[k + 1][l].rgbtBlue + copy[k][l + 1].rgbtBlue + copy[k + 1][l + 1].rgbtBlue)/3.0);
                }
                else if (l == width - 1)
                {
                    image[k][l].rgbtRed = round((copy[k + 1][l].rgbtRed + copy[k][l - 1].rgbtRed + copy[k + 1][l - 1].rgbtRed)/3.0);
                    image[k][l].rgbtGreen = round((copy[k + 1][l].rgbtGreen + copy[k][l - 1].rgbtGreen + copy[k + 1][l - 1].rgbtGreen)/3.0);
                    image[k][l].rgbtBlue = round((copy[k + 1][l].rgbtBlue + copy[k][l - 1].rgbtBlue + copy[k + 1][l - 1].rgbtBlue)/3.0);
                }
                else
                {
                    image[k][l].rgbtRed = round((copy[k][l - 1].rgbtRed + copy[k][l + 1].rgbtRed + copy[k + 1][l - 1].rgbtRed + copy[k + 1][l].rgbtRed + copy[k + 1][l + 1].rgbtRed)/5.0);
                    image[k][l].rgbtGreen = round((copy[k][l - 1].rgbtGreen + copy[k][l + 1].rgbtGreen + copy[k + 1][l - 1].rgbtGreen + copy[k + 1][l].rgbtGreen + copy[k + 1][l + 1].rgbtGreen)/5.0);
                    image[k][l].rgbtBlue = round((copy[k][l - 1].rgbtBlue + copy[k][l + 1].rgbtBlue + copy[k + 1][l - 1].rgbtBlue + copy[k + 1][l].rgbtBlue + copy[k + 1][l + 1].rgbtBlue)/5.0);
                }
            }
            else if (k == height - 1)
            {
                if (l == 0)
                {
                   image[k][l].rgbtRed = round((copy[k - 1][l].rgbtRed + copy[k - 1][l + 1].rgbtRed + copy[k][l + 1].rgbtRed)/3.0);
                    image[k][l].rgbtGreen = round((copy[k - 1][l].rgbtGreen + copy[k - 1][l + 1].rgbtGreen + copy[k][l + 1].rgbtGreen)/3.0);
                    image[k][l].rgbtBlue = round((copy[k - 1][l].rgbtBlue + copy[k - 1][l + 1].rgbtBlue + copy[k][l + 1].rgbtBlue)/3.0);
                }
                else if (l == width - 1)
                {
                    image[k][l].rgbtRed = round((copy[k - 1][l].rgbtRed + copy[k - 1][l - 1].rgbtRed + copy[k][l - 1].rgbtRed)/3.0);
                    image[k][l].rgbtGreen = round((copy[k - 1][l].rgbtGreen + copy[k - 1][l - 1].rgbtGreen + copy[k][l - 1].rgbtGreen)/3.0);
                    image[k][l].rgbtBlue = round((copy[k - 1][l].rgbtBlue + copy[k - 1][l - 1].rgbtBlue + copy[k][l - 1].rgbtBlue)/3.0);
                }
                else
                {
                    image[k][l].rgbtRed = round((copy[k][l - 1].rgbtRed + copy[k][l + 1].rgbtRed + copy[k - 1][l - 1].rgbtRed + copy[k - 1][l].rgbtRed + copy[k - 1][l + 1].rgbtRed)/5.0);
                    image[k][l].rgbtGreen = round((copy[k][l - 1].rgbtGreen + copy[k][l + 1].rgbtGreen + copy[k - 1][l - 1].rgbtGreen + copy[k - 1][l].rgbtGreen + copy[k - 1][l + 1].rgbtGreen)/5.0);
                    image[k][l].rgbtBlue = round((copy[k][l - 1].rgbtBlue + copy[k][l + 1].rgbtBlue + copy[k - 1][l - 1].rgbtBlue + copy[k - 1][l].rgbtBlue + copy[k - 1][l + 1].rgbtBlue)/5.0);
                }
            }
            else
            {
                if (l == 0)
                {
                    image[k][l].rgbtRed = round((copy[k - 1][l].rgbtRed + copy[k + 1][l].rgbtRed + copy[k - 1][l + 1].rgbtRed + copy[k][l + 1].rgbtRed + copy[k + 1][l + 1].rgbtRed)/5.0);
                    image[k][l].rgbtGreen = round((copy[k - 1][l].rgbtGreen + copy[k + 1][l].rgbtGreen + copy[k - 1][l + 1].rgbtGreen + copy[k][l + 1].rgbtGreen + copy[k + 1][l + 1].rgbtGreen)/5.0);
                    image[k][l].rgbtBlue = round((copy[k - 1][l].rgbtBlue + copy[k + 1][l].rgbtBlue + copy[k - 1][l + 1].rgbtBlue + copy[k][l + 1].rgbtBlue + copy[k + 1][l + 1].rgbtBlue)/5.0);
                }
                else if (l == width - 1)
                {
                    image[k][l].rgbtRed = round((copy[k -1][l].rgbtRed + copy[k + 1][l].rgbtRed + copy[k - 1][l - 1].rgbtRed + copy[k][l - 1].rgbtRed + copy[k + 1][l - 1].rgbtRed)/5.0);
                    image[k][l].rgbtGreen = round((copy[k - 1][l].rgbtGreen + copy[k + 1][l].rgbtGreen + copy[k - 1][l - 1].rgbtGreen + copy[k][l - 1].rgbtGreen + copy[k + 1][l - 1].rgbtGreen)/5.0);
                    image[k][l].rgbtBlue = round((copy[k - 1][l].rgbtBlue + copy[k + 1][l].rgbtBlue + copy[k - 1][l - 1].rgbtBlue + copy[k][l - 1].rgbtBlue + copy[k + 1][l - 1].rgbtBlue)/5.0);
                }
                else
                {
                    image[k][l].rgbtRed = round((copy[k - 1][l - 1].rgbtRed + copy[k - 1][l].rgbtRed + copy[k - 1][l + 1].rgbtRed + copy[k][l - 1].rgbtRed + copy[k][l + 1].rgbtRed + copy[k + 1][l - 1].rgbtRed + copy[k + 1][l].rgbtRed + copy[k + 1][l + 1].rgbtRed)/5.0);
                    image[k][l].rgbtGreen = round((copy[k - 1][l - 1].rgbtGreen + copy[k - 1][l].rgbtGreen + copy[k - 1][l + 1].rgbtGreen + copy[k][l - 1].rgbtGreen + copy[k][l + 1].rgbtGreen + copy[k + 1][l - 1].rgbtGreen + copy[k + 1][l].rgbtGreen + copy[k + 1][l + 1].rgbtGreen)/5.0);
                    image[k][l].rgbtBlue = round((copy[k - 1][l - 1].rgbtBlue + copy[k - 1][l].rgbtBlue + copy[k - 1][l + 1].rgbtBlue + copy[k][l - 1].rgbtBlue + copy[k][l + 1].rgbtBlue + copy[k + 1][l - 1].rgbtBlue + copy[k + 1][l].rgbtBlue + copy[k + 1][l + 1].rgbtBlue)/5.0);
                }
            }
        }
    }
    return;
}
