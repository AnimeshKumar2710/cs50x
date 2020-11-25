//taking a RAW file and recovering the .jpg files that are deleted
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef uint8_t BYTE;   //size of byte
int SIZE = 512; //number of bytes in a chunk


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");   //opening the raw file
    FILE *NEW = NULL;   //making file pointer for images

    if (file == NULL)
    {
        printf("File not found");
        return 2;
    }

    int count = 0;
    int imgopen = 0;
    BYTE buffer[SIZE];



    while (1)
    {
        size_t Bytescount = fread(buffer, sizeof(BYTE), SIZE, file);    // reading file and storing the number of bytes

        if (feof(file)) //checking the end of fole
        {
            break;
        }


        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)    //checking the starting bytes
        {
            if (imgopen == 1)
            {
                fclose(NEW);    //closing the file

            }
            else
            {
                imgopen = 1;
            }

            char img[8];

            sprintf(img, "%03i.jpg", count);    //setting the name of the image
            NEW = fopen(img, "w");  //opening the new image file
            count++;

        }



        if (imgopen == 1)
        {
            fwrite(buffer, sizeof(BYTE), Bytescount, NEW);  //writing the image, and using the size that we get in bytecount
        }



    }

    fclose(NEW);
    fclose(file);   //closing the files
    return 0;

}

//used cplusplus.com for reference with fread and write
