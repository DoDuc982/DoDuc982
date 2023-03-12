#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbGray;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            rgbGray = round((image[i][j].rgbtRed +image[i][j].rgbtBlue +image[i][j].rgbtGreen)/3);
            image[i][j].rgbtRed = rgbGray;
            image[i][j].rgbtGreen = rgbGray;
            image[i][j].rgbtBlue = rgbGray;
        }
    }
    return;
}
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaBlue;
    int sepiaRed;
    int sepiaGreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaBlue = limit(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));
            sepiaGreen = limit(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            sepiaRed = limit(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) {

            /** Swap pixels from left to right */
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtRed = temp[2];

        }
    }
    return;
}

int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width] , int color_position)
{
    float counter = 0;
    int sum = 0;
    for (int k = i - 1; k <  (i + 2); k++)
    {
        for (int l = j - 1; l < (j + 2); l ++)
        {
            if(k < 0 || l < 0 || k >= height || l >= width)
            {
                continue;
            }
            if (color_position == 0)
            {
                sum += image[k][l].rgbtRed;
            }
            else if (color_position == 1)
            {
                sum += image[k][l].rgbtGreen;
            }
            else
            {
                sum += image[k][l].rgbtBlue;
            }
            counter++;

        }
    }
    return round(sum /counter);
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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getBlur(i, j, height, width, copy, 0);
            image[i][j].rgbtGreen = getBlur(i, j, height, width, copy, 1);
            image[i][j].rgbtBlue = getBlur(i, j, height, width, copy, 2);
        }
    }
    return;
}
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            temp[i][j] = image[i][j];
        }
    }
    int Gx[3][3] = {
        {-1,0,1},
        {-2,0,2},
        {-1,0,1}
    };
    int Gy[3][3] = {
        {-1,-2,-1},
        {0,0,0},
        {1,2,1}
    };
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int redX = 0, greenX=0, blueX=0, redY = 0, greenY=0, blueY=0;
            for(int x=0;x<3;x++){
                for(int y = 0; y <3 ; y++){
                    if(i - 1 + x < 0 || i - 1 + x > height-1 || j-1+y < 0 || j-1+y >width-1) continue;
                    redX += (image[i-1+x][j-1+y].rgbtRed * Gx[x][y]);
                    blueX += (image[i-1+x][j-1+y].rgbtBlue * Gx[x][y]);
                    greenX += (image[i-1+x][j-1+y].rgbtGreen * Gx[x][y]);
                    redY += (image[i-1+x][j-1+y].rgbtRed * Gy[x][y]);
                    blueY += (image[i-1+x][j-1+y].rgbtBlue * Gy[x][y]);
                    greenY += (image[i-1+x][j-1+y].rgbtGreen * Gy[x][y]);
                }
            }
            int red = round(sqrt(redX*redX + redY*redY));
            int blue = round(sqrt(blueX*blueX + blueY*blueY));
            int green = round(sqrt(greenX*greenX +greenY*greenY));
            if(red > 255){
                red = 255;
            }
            if(green>255){
                green=255;
            }
            if(blue>255){
                blue=255;
            }
            temp[i][j].rgbtRed =red;
            temp[i][j].rgbtBlue =blue;
            temp[i][j].rgbtGreen =green;
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}
