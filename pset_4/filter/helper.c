#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
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
            int sepia[3];
            sepia[0] = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepia[1] = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepia[2] = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            for (int k = 0; k < 3; k++)
            {
                if (sepia[k] > 255)
                {
                    sepia[k] = 255;
                }
            }
            image[i][j].rgbtRed = sepia[0];
            image[i][j].rgbtGreen = sepia[1];
            image[i][j].rgbtBlue = sepia[2];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int tempR = image[i][width - j - 1].rgbtRed;
            int tempG = image[i][width - j - 1].rgbtGreen;
            int tempB = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = image[i][j].rgbtRed;
            image[i][width - j - 1].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width - j - 1].rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = tempR;
            image[i][j].rgbtGreen = tempG;
            image[i][j].rgbtBlue = tempB;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rgbtR = 0;
            float rgbtG = 0;
            float rgbtB = 0;
            int cnt = 0;

            // lt - left-top
            // br - bottom-right
            for (int lt = i - 1; lt < i + 2; lt++)
            {
                for (int br = j - 1; br < j + 2; br++)
                {
                    if (lt< 0 || lt > height - 1)
                    {
                        continue;
                    }

                    if (br < 0 || br > width - 1)
                    {
                        continue;
                    }
                    rgbtR += image[lt][br].rgbtRed;
                    rgbtB += image[lt][br].rgbtBlue;
                    rgbtG += image[lt][br].rgbtGreen;
                    cnt++;
                }
            }

            newImage[i][j].rgbtRed = round(rgbtR / (float) cnt);
            newImage[i][j].rgbtGreen = round(rgbtG / (float) cnt);
            newImage[i][j].rgbtBlue = round(rgbtB / (float) cnt);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = newImage[i][j].rgbtRed;
            image[i][j].rgbtBlue = newImage[i][j].rgbtBlue;
            image[i][j].rgbtGreen = newImage[i][j].rgbtGreen;
        }
    }
    return;
}
