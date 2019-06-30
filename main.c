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
    node* root = NULL;
    comparer int_comp = compare;
    char str[MAX_WORD];
	hash HASH_TABLE;	/* initialize HashTable */
	hash* hash_ptr = &HASH_TABLE;

	HASH_TABLE.h_ptr = HASH_TABLE.hashArr[ZERO];

    Print_intro();

	hashInitialize(hash_ptr);
	
    /* initialize RBT root */
    strcpy(str, "This is first root word");
    root = RB_INSERT(root,1,str);
      
    if (argc == MAX_FILES - ONE) {
		printf("Missing Filename\n");
		return(1);
	} else {
        File_to_Hash(argv[ONE], hash_ptr);
	    root = File_to_RBT(argv[TWO], root);
    }

    printf("\n\n==THE FINAL RBT==\n\n");
    display_tree(root);
	printHashTable(hash_ptr);
	Print_outro();

    return 0;
}

void Print_intro ()
{
    printf("\n****************************************");
	printf("\nThis program read words from files,");
	printf("\nand found the English words with mistake.\n");
	printf("****************************************\n");
}

void Print_outro ()
{
    printf("\n****************************************");
	printf("\nThis program finish is jobs successfully.\n");
	printf("****************************************\n");
}

/* root = insert_node(root,int_comp,1,str); */

/*strcpy(str, "roww");
		if (findHash(hash_ptr, str) == TRUE)
			printf("Found the word %s in the hash table\n", str);
		else
			printf("The word %s not in the hash table!\n", str);*/
