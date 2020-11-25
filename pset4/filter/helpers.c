//applying a few different filters on an image
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE avg;

    for (int i = 0; i < height; i++)    //looping height
    {
        for (int j = 0; j < width; j++) //looping width
        {
            avg = ((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0) + 0.50; //finding avrage

            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)    //looping height
    {
        for (int j = 0; j < (width / 2); j++)   //looping halfway through width
        {

            temp.rgbtBlue = image[i][j].rgbtBlue;    //saving value of i*j position in temp
            temp.rgbtRed = image[i][j].rgbtRed;
            temp.rgbtGreen = image[i][j].rgbtGreen;

            image[i][j].rgbtBlue =  image[i][(width - 1 - j)].rgbtBlue;  //puting i*(width - 1 - j) in i*j
            image[i][j].rgbtRed = image[i][(width - 1  - j)].rgbtRed;
            image[i][j].rgbtGreen = image[i][(width - 1 - j)].rgbtGreen;
 
            image[i][(width - 1 - j)].rgbtBlue =  temp.rgbtBlue; //puting saved value in i*(width - 1 - j
            image[i][(width - 1 - j)].rgbtRed = temp.rgbtRed;
            image[i][(width - 1 - j)].rgbtGreen =  temp.rgbtGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int Blue, Red, Green;
    RGBTRIPLE temp[height][width];


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;

            Blue = image[i][j].rgbtBlue;    //center pixel
            Red = image[i][j].rgbtRed;
            Green = image[i][j].rgbtGreen;
            count++;


            if (i > 0)
            {
                Blue += image[i - 1][j].rgbtBlue; //upper center pixel
                Red += image[i - 1][j].rgbtRed;
                Green += image[i - 1][j].rgbtGreen;
                count++;


                if (j > 0)
                {
                    Blue += image[i - 1][j - 1].rgbtBlue;   //upper left pixel
                    Red += image[i - 1][j - 1].rgbtRed;
                    Green += image[i - 1][j - 1].rgbtGreen;
                    count++;

                }
                if (j < width - 1)
                {
                    Blue += image[i - 1][j + 1].rgbtBlue;   //upper right pixel
                    Red += image[i - 1][j + 1].rgbtRed;
                    Green += image[i - 1][j + 1].rgbtGreen;
                    count++;

                }
            }

            if (j > 0)
            {
                Blue += image[i][j - 1].rgbtBlue;   //center left pixel
                Red += image[i][j - 1].rgbtRed;
                Green += image[i][j - 1].rgbtGreen;
                count++;

            }

            if (i < height - 1)
            {
                Blue += image[i + 1][j].rgbtBlue;   //bottom center pixel
                Red += image[i + 1][j].rgbtRed;
                Green += image[i + 1][j].rgbtGreen;
                count++;


                if (j < width - 1)
                {
                    Blue += image[i + 1][j + 1].rgbtBlue;   //bottom right pixel
                    Red += image[i + 1][j + 1].rgbtRed;
                    Green += image[i + 1][j + 1].rgbtGreen;
                    count++;

                }
                if (j > 0)
                {
                    Blue += image[i + 1][j - 1].rgbtBlue;   //bottom left pixel
                    Red += image[i + 1][j - 1].rgbtRed;
                    Green += image[i + 1][j - 1].rgbtGreen;
                    count++;

                }
            }

            if (j < width - 1)
            {
                Blue += image[i][j + 1].rgbtBlue;   //center right pixel
                Red += image[i][j + 1].rgbtRed;
                Green += image[i][j + 1].rgbtGreen;
                count++;

            }


            temp[i][j].rgbtBlue = (Blue * 1.0 / count) + 0.5;   //finding average and storing after rounding up 
            temp[i][j].rgbtRed = (Red * 1.0 / count) + 0.5;
            temp[i][j].rgbtGreen = (Green * 1.0 / count) + 0.5;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue; // setting in the image
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height + 2][width + 2];
    int Gx[3][3] = { {-1, 0, 1},    
        {-2, 0, 2},
        {-1, 0, 1}
    };  //setting Gx

    int Gy[3][3] = { {-1, -2, -1},
        {0,  0,  0},
        {1,  2,  1}
    };  //setting Gy




    for (int i = 0; i < height + 2; i ++)
    {
        for (int j = 0; j < width + 2; j ++)
        {
            if (i == 0 || i == height + 1 || j == 0 || j == width + 1)
            {
                temp[i][j].rgbtRed = 0;
                temp[i][j].rgbtBlue = 0;
                temp[i][j].rgbtGreen = 0;
            }
            else
            {
                temp[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed;
                temp[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
                temp[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
            }
        }
    }   //creating a temp image with padding
    
    

    for (int i = 1; i < height + 1; i ++)
    {
        for (int j = 1; j < width + 1; j ++)
        {
            int redx = 0, redy = 0, greenx = 0, greeny = 0, bluex = 0, bluey = 0;
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    redx += temp[i - 1 + k][j - 1 + l].rgbtRed * Gx[k][l];  //oprating Gx and Gy 
                    redy += temp[i - 1 + k][j - 1 + l].rgbtRed * Gy[k][l];

                    greenx += temp[i - 1 + k][j - 1 + l].rgbtGreen * Gx[k][l];
                    greeny += temp[i - 1 + k][j - 1 + l].rgbtGreen * Gy[k][l];

                    bluex += temp[i - 1 + k][j - 1 + l].rgbtBlue * Gx[k][l];
                    bluey += temp[i - 1 + k][j - 1 + l].rgbtBlue * Gy[k][l];
                }
            }
            int Sqroot;

            Sqroot = sqrt((redx * redx) + (redy * redy)) * 1.0 + 0.5;   // setting values 

            if (Sqroot > 255)
            {
                image[i - 1][j - 1].rgbtRed = 255;
            }
            else
            {
                image[i - 1][j - 1].rgbtRed = Sqroot;
            }

            Sqroot = sqrt((greenx * greenx) + (greeny * greeny)) * 1.0 + 0.5;

            if (Sqroot > 255)
            {
                image[i - 1][j - 1].rgbtGreen = 255;
            }
            else
            {
                image[i - 1][j - 1].rgbtGreen = Sqroot;
            }

            Sqroot = sqrt((bluex * bluex) + (bluey * bluey)) * 1.0 + 0.5;

            if (Sqroot > 255)
            {
                image[i - 1][j - 1].rgbtBlue = 255;
            }
            else
            {
                image[i - 1][j - 1].rgbtBlue = Sqroot;
            }

        }
    }


    return;
}
