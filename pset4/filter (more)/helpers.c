#include "helpers.h"
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i<height; i++ )
    {
        for (int j = 0; j<width; j++ )
        {
            float a = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            a = (float)a/3;
            float c = a*10;
            int b = (int)c;
            b = b%10;
            if (b>=5){
                a+=1;
            }
            if (a <= 255)
            {
                image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = (int)a;
            }
            else
            {
                image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = 255;

            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i<height; i++ )
    {
        for (int j = 0; j < width/2; j++ )
        {
             if (width%2 == 0)
        {
            int a = j +1- width;
            if (a <0)
            {
                a = -a;
            }
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][a];
            image[i][a] = temp;
        }
        else
        {
        
            int a = j + 1 - width;
            if (a <0)
            {
                a = -a;
            }
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][a];
            image[i][a] = temp;
        }   
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pix[height][width];
    for (int i = 0; i<height; i++ )
    {
        for (int j = 0; j<width; j++)
        {
            float averagergbtRed=0;
            float averagergbtBlue=0;
            float averagergbtGreen = 0;
            int no_of_pixels = 0;
            no_of_pixels = 0;
            for(int blury = -1; blury<2; blury++)
            {
            for(int blurx = -1; blurx<2; blurx++)
                {
                    if(i+blury>=0 && i+blury< height && j+blurx >=0 && j+blurx < width)
                    {
                        no_of_pixels+=1;
                        averagergbtRed += image[i+blury][j+blurx].rgbtRed;
                        averagergbtBlue += image[i+blury][j+blurx].rgbtBlue;
                        averagergbtGreen += image[i+blury][j+blurx].rgbtGreen;

                    }
                }

            }
            averagergbtRed = averagergbtRed/no_of_pixels;
            averagergbtBlue = averagergbtBlue/no_of_pixels;
            averagergbtGreen = averagergbtGreen/no_of_pixels;
            float rounder[3] = {averagergbtRed, averagergbtBlue, averagergbtGreen};
            for (int roun = 0; roun < 3; roun++)
            {
            float c = rounder[roun]*10;
            int b = (int)c;
            b = b%10;
            if (b>=5){
                rounder[roun]+=1;
            }
            averagergbtRed = rounder[0];
            averagergbtBlue = rounder[1];
            averagergbtGreen = rounder[2];
            
            
            }
            if (averagergbtRed > 255 )
            {
                averagergbtRed = 255;
            }
            if (averagergbtBlue > 255 )
            {
                averagergbtBlue = 255;
            }
            if (averagergbtGreen > 255 )
            {
                averagergbtGreen = 255;
            }
            pix[i][j].rgbtRed= (int)averagergbtRed;
            pix[i][j].rgbtGreen= (int)averagergbtGreen;
            pix[i][j].rgbtBlue= (int)averagergbtBlue;

        }
    }
    for (int i = 0; i<height; i++ )
    {
        for (int j = 0; j<width; j++)
        {image[i][j] = pix[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
int Gx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
int Gy[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};
RGBTRIPLE pix[height][width];
    //iterating through values
    for (int i = 0; i<height; i++ )
    {
        for (int j = 0; j<width; j++)
        {
            //initializing all values
            float xarR =0;
            float xarB =0;
            float xarG = 0;
            float yarR =0;
            float yarB =0;
            float yarG = 0;
            float SbR =0;
            float SbB =0;
            float SbG = 0;
            for(int squarey = -1; squarey<2; squarey++)
            {
            for(int squarex = -1; squarex<2; squarex++)
            {
                    
            if (j+squarex > width-1 || i+squarey > height-1 || i+squarey < 0 || j+squarex < 0 )
            {
                true;
            }
            else
            {
                //adding up Gx and Gy multiples
                xarR += image[i+squarey][j+squarex].rgbtRed*Gx[squarey+1][squarex+1];
                xarB += image[i+squarey][j+squarex].rgbtBlue*Gx[squarey+1][squarex+1];
                xarG += image[i+squarey][j+squarex].rgbtGreen*Gx[squarey+1][squarex+1];
                yarR += image[i+squarey][j+squarex].rgbtRed*Gy[squarey+1][squarex+1];
                yarB += image[i+squarey][j+squarex].rgbtBlue*Gy[squarey+1][squarex+1];
                yarG += image[i+squarey][j+squarex].rgbtGreen*Gy[squarey+1][squarex+1];
            }
            }
            }
            //Sobel operator
            SbR = xarR*xarR + yarR*yarR;
            SbB = xarB*xarB + yarB*yarB;
            SbG = xarG*xarG + yarG*yarG;
            SbG = sqrt(SbG);
            SbB = sqrt(SbB);
            SbR = sqrt(SbR);
            //to round of the value to closest integer
            float rounder[3] = {SbR, SbB, SbG};
            for (int roun = 0; roun < 3; roun++)
                {
                float c = rounder[roun]*10;
                int b = (int)c;
                b = b%10;
                if (b>=5)
                {
                    rounder[roun]+=1;
                }
                }
            SbR = rounder[0];
            SbB = rounder[1];
            SbG = rounder[2];
            
            //capping at 255
            
            if (SbG>255)
            {
                SbG = 255;
            }
            if (SbR>255)
            {
                SbR = 255;
            }
            if (SbB>255)
            {
                SbB = 255;
            }
            //loading into temp
            pix[i][j].rgbtRed = (int)SbR;
            pix[i][j].rgbtBlue = (int)SbB;
            pix[i][j].rgbtGreen = (int)SbG;
        }
    }
    //loading from temp to actual image
    for (int i = 0; i<height; i++ )
    {
        for (int j = 0; j<width; j++)
        {
            image[i][j] = pix[i][j];
        }
    }
    return;
    
}
