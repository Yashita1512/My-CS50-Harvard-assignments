#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            image[i][j].rgbtRed = (sepiaRed < 255) ? sepiaRed : 255;
            image[i][j].rgbtGreen = (sepiaGreen < 255) ? sepiaGreen : 255;
            image[i][j].rgbtBlue = (sepiaBlue < 255) ? sepiaBlue : 255;
        }
    }
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            image[i][j].rgbtRed = copy[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = copy[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][width - j - 1].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    int redsum = 0;
    int greensum = 0;
    int bluesum = 0;
    int count = 0;

    //for middle pixel
     for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            
            for (int k = -1; k <= 1; k++){
                for (int l = -1; l <= 1; l++){

                    if ( (i + k) >= 0 && (i + k) < height && (j + l) >= 0 && (j + l) < width){
                        redsum += copy[i + k][j + l].rgbtRed;
                        greensum += copy[i + k][j + l].rgbtGreen;
                        bluesum += copy[i + k][j + l].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = (round((float)redsum/count) < 255) ? round((float)redsum/count) : 255;
            image[i][j].rgbtGreen = (round((float)greensum/count) < 255) ? round((float)greensum/count) : 255;
            image[i][j].rgbtBlue = (round((float)bluesum/count) < 255) ? round((float)bluesum/count) : 255;

            redsum = 0;
            greensum = 0;
            bluesum = 0;
            count = 0;
        }
     }
    return;
}
