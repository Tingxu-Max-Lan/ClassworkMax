// Copies a BMP file
// Max 2023/1/31
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    //multiplier
    int n = atoi(argv[1]);
    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int oldWidth = bi.biWidth;
    int oldHeight = bi.biHeight;
    bi.biWidth *= n;
    bi.biHeight *= n;
    int oldPad = (4 - (oldWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newPad = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biSizeImage = ((sizeof(RGBTRIPLE)*bi.biWidth) + newPad) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    // write outfile
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
     fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


        //creates an array the size of a line from the image for fwrite
 RGBTRIPLE scanline[bi.biWidth * sizeof(RGBTRIPLE)];
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(oldHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline

            for (int j = 0; j < oldWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

           //we create arrays for each pixel to write to later
            for(int c = 0; c < n; c++){
            scanline[(j*n)+c] = triple;
            }


        }

        // skip over padding, if any
        fseek(inptr, oldPad, SEEK_CUR);
    //write what we have scanned 
    for (int q= 0; q< n; q++){
    fwrite(scanline, sizeof(RGBTRIPLE),bi.biWidth,outptr);
        for (int k = 0; k < newPad; k++)
        {
            fputc(0x00, outptr);
        }
    }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
