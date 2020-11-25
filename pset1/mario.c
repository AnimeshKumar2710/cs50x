//creating a pattern for mario
/*
    #  #
   ##  ##
  ###  ###
 ####  ####
*/
#include <stdio.h>
#include <cs50.h>

void mario(int height);

int main()
{  
    int height = 0;
    do
    {
        height = get_int("Enter hight:\n");
    }
    while (height < 1 || height > 8);
    
    mario(height);
}



void mario(int height)
{
    for (int i = 0 ; i < height ; i++)        // For hight 
    {   
        for (int j = 0 ; j < height ; j++)    // loop for the first set of #
        {
            if (j < (height - 1 - i))
            {
                printf(" ");
            }
            else 
            {
                printf("#");
            }
        }
        
        printf("  ");
        for (int j = 0 ; j <= i ; j++)    // loop for the second set
        {
            printf("#"); 
        }
        printf("\n");
    }
}
