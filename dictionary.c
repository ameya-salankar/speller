/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

#include <stdio.h>

#include <stdlib.h>

typedef struct _trie
{
	bool is_word;
	struct _trie* next[27];
}
node;

node* root,* q;

long long number = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int index;
	q = root;

	for(int k = 0; word[k] != '\0'; k++)
    {
		index = ctoindex(word[k]);

		if(q->next[index] == NULL)
			return false;

		q = q->next[index];
    }

    if(q->is_word == false)
		return false;
	else
	    return true;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
	FILE *fp = fopen(dictionary, "r");
	if(fp == NULL)
	{
	    printf("Couldn't open %s", dictionary);
	    return false;
	}
	char c = '0';
	int index_c = 0;

	root = (node*) calloc(1, sizeof(node));

	while(c != EOF)
	{
		q = root;
		c = fgetc(fp);

		for ( ; c != '\n' && c != EOF; c = fgetc(fp))
		{
			index_c = ctoindex(c);
			if (q->next[index_c] == NULL)
			{
				q->next[index_c] = (node*) calloc(1, sizeof(node));
				if(q->next[index_c] == NULL)
				{
					printf("Ran out of memory\n");
					return false;
				}
			}

			q = q->next[index_c];
		}

		q->is_word = true;
		number++;
	}

	fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    q = root;

    return (unsigned int) (number-1);
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
	node* temp;
	temp = q;

	for(int n = 0; n < 27; n++)
	{
		if(q->next[n] != NULL)
		{
			q = q->next[n];
			unload();
			q = temp;
		}
	}

	free(temp);
	return true;
}

int ctoindex(char c)
{
    if(c >= 'a' && c <= 'z')
        return (int)((int)(c - 'a'));
    else if(c >= 'A' && c <= 'Z')
        return (int)((int)(c - 'A'));
    else if(c == '\'')
    	return 26;

    return -1;
}