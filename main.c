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

    Print_intro();

    /* initialize RBT root */
    strcpy(str, "This is first root word");
    root = insert_node(root,int_comp,1,str); 
    /* printf("\n\ndata = %d\n\n", root->data);
    printf("\n\ncolor = %d\n\n", root->color);
    printf("\n\nword = %s\n\n", root->word); */

    
    if (argc == MAX_FILES - ONE) {
		printf("Missing Filename\n");
		return(1);
	} else {
        File_to_Hash(argv[ONE]);
	    File_to_RBT(argv[TWO], root);
    }

    printf("\n\n==THE RBT==\n\n");
    display_tree(root);

    return 0;
}

void Print_intro ()
{
    printf("\n****************************************");
	printf("\nThis program read from files");
	printf("\nand found English words with mistake.\n");
	printf("****************************************\n");
}