// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 17576; //total of 5 letters considred in the table 26^5
unsigned int wordcount = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = strlen(word);   //getting the length
    char temp[n + 1];
    temp[n] = '\0';
    for (int i = 0; i < n; i++) //converting the string into lower
    {
        temp[i] = tolower(word[i]);
    }
    int hashcode = hash(temp);
    node *temp_node = table[hashcode];
    if (temp_node == NULL)  //if nothing on the table
    {
        return false;
    }
    while (temp_node != NULL)   //
    {
        if (strcmp(temp_node -> word, temp) == 0)   //checking if it belongs to the dictionary
        {
            return true;
        }
        else
        {
            temp_node = temp_node -> next;  //moving to the next word
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int index = 0;
    for (int i = 0; i < strlen(word) && i < 3; i ++)
    {
        if (i > 0)
        {
            index = (index + 1) * 26 + (tolower(word[i]) - 97);
        }
        else
        {
            index = (tolower(word[i]) - 97);
        }
    }
    return index % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");    //opening file
    if (file == NULL)   //checking file
    {
        return false;
    }

    char temp[LENGTH + 1];  //a temp array
    while (fscanf(file, "%s", temp) != EOF)
    {



        node *n = malloc(sizeof(node)); //new node
        if (n == NULL)  //checking if it is allocated
        {
            fclose(file);
            return false;
        }

        

        n->next = NULL; //setting next to Null
        strcpy(n->word, temp);  //setting word

        unsigned int index = hash(n->word);  //getting the index
        n->next = table[index]; //setting in the front of the list
        table[index] = n;

        wordcount++;    //counting words
    }


    fclose(file);   //closing file

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *Current = table[i];   //going through array
        while (Current != NULL)
        {
            node *Delete = Current;
            Current = Current -> next;
            free(Delete);   //deleting the memory
        }
    }
    return true;
}
