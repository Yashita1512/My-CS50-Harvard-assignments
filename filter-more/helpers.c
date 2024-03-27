#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx [3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
    int Gy[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Gy[i][j] = Gx[j][i];
        }
    }

    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    //for middle pixel
     for (int i = 0; i < height; i++)
     {
        for (int j = 0; j < width; j++)
        {
        int redsum = 0;
        int greensum = 0;
        int bluesum = 0;
        float redsumX = 0;
        float greensumX = 0;
        float bluesumX = 0;
        float redsumY = 0;
        float greensumY = 0;
        float bluesumY = 0;

        int count = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if ((i + k) >= 0 && (i + k) < height && (j + l) >= 0 && (j + l) < width)
                    {
                        redsumX += ((copy[i + k][j + l].rgbtRed)*(float)Gx[k + 1][l + 1]);
                        greensumX +=((copy[i + k][j + l].rgbtGreen)*(float)Gx[k + 1][l + 1]);
                        bluesumX += ((copy[i + k][j + l].rgbtBlue)*(float)Gx[k + 1][l + 1]);

                        redsumY +=((copy[i + k][j + l].rgbtRed)*(float)Gy[k + 1][l + 1]);
                        greensumY += ((copy[i + k][j + l].rgbtGreen)*(float)Gy[k + 1][l + 1]);
                        bluesumY += ((copy[i + k][j + l].rgbtBlue)*(float)Gy[k + 1][l + 1]);

                        count++;
                    }
                }
            }

            redsum = round(sqrt(pow(redsumX,2) + pow(redsumY,2)));
            greensum = round(sqrt(pow(greensumX,2) + pow(greensumY,2)));
            bluesum = round(sqrt(pow(bluesumX,2) + pow(bluesumY,2)));

            image[i][j].rgbtRed = (int)fmin(redsum, 255);
            image[i][j].rgbtGreen = (int)fmin(greensum, 255);
            image[i][j].rgbtBlue = (int)fmin(bluesum, 255);
        }
     }
    return;
}
