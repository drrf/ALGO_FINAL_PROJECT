/*
 *          File: file_to_x.c
 *        Author: Ron F. <>
 * Last Modified: June, 2019
 *         Topic: RBT & Hash table
 * ----------------------------------------------------------------
 */

#include "my_h.h"

/* enter thw words from file to RBT */
int File_to_RBT (char* file_n, node* root)
{
	FILE *fp;
	char *filename;
	char ch;
	char word[MAX_WORD];
	int w_ind = ZERO;
	int rbt_ind = ONE;

	comparer int_comp = compare;

	filename = file_n;
	printf("Filename : %s\n", filename);

	/* Open file in read-only mode */
	fp = fopen(filename,"r");

	/* If file opened successfully, then print the contents */
	if ( fp )
	{
		printf("File contents:\n");
		while ( (ch = fgetc(fp)) != EOF ){
			if (isspace(ch)){
				word[w_ind] = '\0';
				w_ind = ZERO;
                root = insert_node(root,int_comp,++rbt_ind,word);
			} else {
				word[w_ind++] = ch;
			}
		}
	} else {
		printf("Failed to open the file\n");
	}

	return 0;
}


/* enter thw words from file to Hash */
int File_to_Hash (char* file_n)
{
	FILE *fp;
	char *filename;
	char ch;

	filename = file_n;
	printf("Filename : %s\n", filename);

	/* Open file in read-only mode */
	fp = fopen(filename,"r");

	/* If file opened successfully, then print the contents */
	if ( fp )
	{
		printf("File contents:\n");
		while ( (ch = fgetc(fp)) != EOF )
			printf("%c",ch);

	} else {
		printf("Failed to open the file\n");
	}

	return 0;
}