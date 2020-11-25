//Code to test redability of a text  =and giving the level required to read the text

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
    string text = get_string("Text:\n");    //Getting the text
    int n = strlen(text);   //Length of the text
    int letters = 0, words = 1, sentences = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))   //checking if alphabet using ctype.h
        {
            letters++;
        }
        else if (text[i] == '.' || text[i] == '?')  //Testing end of sentence
        {
            sentences++;

        }
        else if (text[i] == ' ') //checking number of words
        {
            words++;
        }
    }

    float L = (float) letters / words;
    float S = (float) sentences / words;
    float index = 005.88 * L - 029.6 * S - 15.8;    //Finding index


    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)(index + 0.5)); //adding 0.5 to round up or down
    }
}
