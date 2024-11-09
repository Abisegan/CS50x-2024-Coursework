// Implements a dictionary's functionality
#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];
int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hash_val = hash(word);
    for (node *cursor = table[hash_val]; cursor != NULL; cursor = cursor->next)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int f_letter;
    unsigned int s_letter;
    if (strlen(word) < 2)
    {
        f_letter = toupper(word[0]) - 'A';
        s_letter = toupper(word[1]) - 'A';
        return (f_letter * 26);
    }
    else
    {
        f_letter = toupper(word[0]) - 'A';
        s_letter = toupper(word[1]) - 'A';
        return (f_letter * 26) + s_letter;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dictionary file
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    char word[LENGTH + 1];
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }
    // read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        // add each word in the list
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        unsigned int hash_val = hash(word);
        strcpy(n->word, word);
        n->next = table[hash_val];
        table[hash_val] = n;
        dict_size++;
    }
    // close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
