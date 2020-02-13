/*
 *          File: check.c
 *        Author: Ron F. <>
 * Last Modified: June, 2019
 *         Topic: RBT & Hash table
 * ----------------------------------------------------------------
 */

#include "my_h.h"

/* check the words on RBT if them also show on hash table*/
int checkRBT (hash* hash_ptr, node *nd)
{
	char word[MAX_WORD];

	if (nd == NULL)
        	return 0;
	if (nd->left == nd || nd->right == nd){  /* if we have bug in RBT exit */
		exit(0);	
		return 0;
	}
    
	/* first recur on left child */
	checkRBT(hash_ptr, nd->left);
	strcpy(word, nd->word);
	/* if found the RBT serch word in hash*/
	if (findHash(hash_ptr,word) == TRUE || nd->data == ONE)	/* ONE == ROOT */
		;
	else {
		printf("The word #%d missing from HASH TABLE: \"%s\"\n", nd->data-ONE, word);
	}
	/* last recur on right child */
	checkRBT(hash_ptr, nd->right);
	return 0;
}
