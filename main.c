/*
 *          File: main.c
 *        Author: Ron F. <>
 * Last Modified: June, 2019
 *         Topic: RBT & Hash table
 * ----------------------------------------------------------------
 */

#include "my_h.h"

int main ( int argc, char *argv[] )
{
	char str[MAX_WORD];
    node* root = NULL;
	hash HASH_TABLE;
	hash* hash_ptr;

	Print_intro();
	
	/* initialize HashTable */
	hash_ptr = &HASH_TABLE;
	HASH_TABLE.h_ptr = HASH_TABLE.hashArr[ZERO];
	hashInitialize(hash_ptr);

    /* initialize HASH_Table & RBT root */
    strcpy(str, "This is first root word");
    root = RB_INSERT(root,ONE,str);
    
	/* if missing files */
    if (argc == MAX_FILES - ONE) {
		printf("EXIT: Missing Files\n");
		return(1);
	}

	/* copy words to hash and RBT */
	File_to_Hash(argv[ONE], hash_ptr);
	root = File_to_RBT(argv[TWO], root);

	/* check and print the final RBT words */
	Print_finalRBT();
	checkRBT(hash_ptr,root);

	
	Print_outro();
    return 0;
}

/* print intro to output */
void Print_intro ()
{
    printf("\n****************************************");
	printf("\nThis program read words from files,");
	printf("\nand found the English words with mistake.\n");
	printf("****************************************\n");
}

/* print headline: THE FINAL RBT to output */
void Print_finalRBT ()
{
    printf("\n\n====================================\n");
	printf("THE FINAL RBT: English words with mistake\n");
	printf("====================================\n\n");
}

/* print outro to output */
void Print_outro ()
{
    printf("\n****************************************");
	printf("\nThis program finish is jobs successfully.\n");
	printf("****************************************\n");
}


