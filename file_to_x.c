/*
 *          File: file_to_x.c
 *        Author: Ron F. <>
 * Last Modified: June, 2019
 *         Topic: RBT & Hash table
 * ----------------------------------------------------------------
 */

#include "my_h.h"

/* enter thw words from file to RBT */
node* File_to_RBT (char* file_n, node* root)
{
	FILE *fp;
	char *filename;
	char ch;
	char word[MAX_WORD];
	int w_ind = ZERO, rbt_ind = ONE;

	filename = file_n;

	/* Open file in read-only mode */
	fp = fopen(filename,"r");
	
	printf("\nTHE TEXT TO CHECK FROM THE FILE \"%s\":\n\n",filename);
	/* If file opened successfully, then print the contents */
	if ( fp )
	{
		while ( (ch = fgetc(fp)) != EOF ){
			printf("%c",ch);
			if (isspace(ch)){ /* WHEN THIS IS END OF WORD */
				word[w_ind] = '\0';
				w_ind = ZERO;
				root = RB_INSERT(root,++rbt_ind,word);	/* INESRT THE WORD TO RBT */
			} else {
				word[w_ind++] = ch;
			}
		}
	} else {
		printf("Failed to open the file : %s\n", filename);
	}
	return root;
}


/* enter thw words from file to Hash */
int File_to_Hash (char* file_n, hash* hash_ptr)
{
	FILE *fp;
	char *filename;
	char ch;
	char word[MAX_WORD];
	int w_ind = ZERO;

	filename = file_n;

	/* Open file in read-only mode */
	fp = fopen(filename,"r");

	/* If file opened successfully, then print the contents */
	if ( fp )
	{
		while ( (ch = fgetc(fp)) != EOF ){
			if (isspace(ch)){	/* WHEN THIS IS END OF WORD */
				word[w_ind] = '\0';
				w_ind = ZERO;
				insertHash(hash_ptr, word);	/* INESRT THE WORD TO HASH TABLE */
			} else {
				word[w_ind++] = ch;
			}
		}
	} else {
		printf("Failed to open the file : %s\n", filename);
	}
	return 0;
}
