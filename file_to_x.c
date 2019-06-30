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
				root = RB_INSERT(root,++rbt_ind,word);
                /*root = insert_node(root,int_comp,++rbt_ind,word);*/
			} else {
				word[w_ind++] = ch;
			}
		}
	} else {
		printf("Failed to open the file\n");
	}
	printf("FINISH File_to_RBT!!\n");
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
				/*hash_ptr->h_ptr = hash_ptr->hashArr[hash_cell++];
				strcpy(hash_ptr->h_ptr, word); */
				insertHash(hash_ptr, word);
			} else {
				word[w_ind++] = ch;
			}
		}
	} else {
		printf("Failed to open the file\n");
	}
	printf("FINISH File_to_Hash!!\n");
	return 0;
}
