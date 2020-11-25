// Creating a cypher code by using the code key and text provided by the user

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2)  //checking if key is provided
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26) //checking if lenght is correct
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            return 1;
        }
        for (int j = i + 1; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                return 1;
            }
        }
    }
    string plaintext = get_string("Plain Text:\n"); //taking input

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))  //if the plain text character is upper
        {
            printf("%c", toupper(argv[1][(int)(plaintext[i]) - 65]));
        }
        else if (islower(plaintext[i])) // if it is lower
        {
            printf("%c", tolower(argv[1][(int)(plaintext[i]) - 97]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");   //line end


}
