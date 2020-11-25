// Checking if a card is valid by checking the creditcard number using Luhn’s Algorithm

#include <stdio.h>
#include <cs50.h>

int sumdigit(int n);
void card(char a, int n);

int main()
{
    char cardcompany;
    int digit = 0, finalsum = 0, count = 1;
    long cardnumber = get_long("enter the card number:\n");
    long temp = cardnumber;

    if (cardnumber < 0)        // INVALID if card number entred is lesss than 0
    {
        printf("INVALID\n");
    }
    else
    {
        while (temp > 0) // Counting the number of digits in the car number
        {
            temp = temp / 10;
            count++;
        }


        if (count < 12 || count > 17)   //if the count of digits is not inbetween 13 and 16 it can't be valid
        {
            printf("INVALID\n");
        }

        else
        {
            for (int i = 0; i < count ; i++)    //Runing the Luhn's Algorithm
            {
                digit = cardnumber % 10;
                cardnumber = cardnumber / 10;

                if (i % 2 == 0)
                {
                    finalsum += digit;
                }
                else if (digit * 2 > 9)
                {
                    finalsum += sumdigit(digit * 2);
                }
                else
                {
                    finalsum += digit * 2;
                }

                if (cardnumber == 34 || cardnumber == 37)   // Checking if the MSBs of the card number represent any of the Companies
                {
                    cardcompany = 'A';
                }
                else if (cardnumber < 56 && cardnumber > 50)
                {
                    cardcompany = 'M';
                }
                else if (cardnumber == 4)
                {
                    cardcompany = 'V';
                }

            }

            if (finalsum % 10 == 0) // If the card passed the Algorithm
            {
                card(cardcompany, count - 1);
            }
            else                //If it doesn't pass the algorithm
            {
                printf("INVALID\n");
            }

        }

    }
}



int sumdigit(int n) //To find the sum of the digits of a number
{
    int Sum = 0;
    while (n)
    {
        Sum += n % 10;
        n = n / 10;
    }
    return Sum;
}


void card(char a, int n)    // Showing the name of the company if it passes
{
    if (a == 'A' && n == 15)
    {
        printf("AMEX\n");
    }
    else if (a == 'M' && n == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (a == 'V' && (n == 13 || n == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");

    }
}
