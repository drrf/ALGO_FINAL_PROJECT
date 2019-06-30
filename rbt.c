/*
 *          File: rbt.c
 *        Author: Ron F. <>
 * Last Modified: June, 2019
 *         Topic: RBT & Hash table
 * ----------------------------------------------------------------
 */

#include "my_h.h"

/* create a new node */
node* create_node(int data, char cp_word[MAX_WORD])
{
    node *new_node = (node*)malloc(sizeof(node));

    if(new_node == NULL)
    {
        fprintf (stderr, "Out of memory!!! (create_node)\n");
        exit(1);
    }
    new_node->data = data;              /* copy the data to the node */
    new_node->Color = Red;              /* ALWAYS new node are red */
    strcpy(new_node->word, cp_word);    /* copy the word to the node */
    new_node->left = NULL;
    new_node->right = NULL;   
    return new_node;
}

node* RB_INSERT(node *root, int data, char cp_word[MAX_WORD])
{
    node *z = create_node(data, cp_word);
    node *y=NULL, *x = root;
    printf("IN UP\n");
    display_tree(root);
    printf("\n");
    if(root == NULL)
    {
        root = z;
        root->Color = Black;
        return root;
    }

    while (x!=NULL)
    {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y==NULL)
        root = z;
    else{
        if (z->data < y->data)
            y->left=z;
        else
            y->right=z;
    }
    z->left = NULL;
    z->right = NULL;
    z->Color=Red;
    printf("\n");
    display_tree(root);
    printf("IN DOWN\n");
    root = RB_INSERT_FIXUP(root,z);
    return root;
}

node* RB_INSERT_FIXUP(node *root, node *z)
{
    node *y=NULL;
    printf("WE up!\n");
    while (z != NULL && z->parent != NULL && (z->parent)->Color==Red)
    {
        printf("0!\n");
        if(z->parent == ((z->parent)->parent)->left){
            y = ((z->parent)->parent)->right;
            printf("1!\n");
            if(y->Color==Red){
                (z->parent)->Color = Black;                 /* CASE 1 */
                y->Color = Black;                           /* CASE 1 */
                ((z->parent)->parent)->Color = Red;         /* CASE 1 */
                z = (z->parent)->parent;                    /* CASE 1 */
                printf("2!\n");
            } else {
                if (z == (z->parent)->right){
                    z = z->parent;                          /* CASE 2 */
                    root = LEFT_ROTATE(root, z);            /* CASE 2 */
                    printf("3!\n");
                }
                (z->parent)->Color = Black;                 /* CASE 3 */
                ((z->parent)->parent)->Color = Red;         /* CASE 3 */
                root = RIGHT_ROTATE(root, (z->parent)->parent);    /* CASE 3 */
                printf("4!\n");
            }
        } else { /* if (z->parent == z->parent->parent->right) */
            y = ((z->parent)->parent)->left;
            printf("5!\n");
            if (y != NULL && y->Color == Red)
            {
                (z->parent)->Color = Black;             /* CASE 1 */
                y->Color = Black;                       /* CASE 1 */
                ((z->parent)->parent)->Color = Red;     /* CASE 1 */
                z = (z->parent)->parent;                /* CASE 1 */
                display_tree(root);
                printf("6!\n");
            } else {
                if (z == (z->parent)->left){
                    z = z->parent;                      /* CASE 2 */
                    root = RIGHT_ROTATE(root, z);       /* CASE 2 */
                    printf("7!\n");
                }
                (z->parent)->Color = Black;             /* CASE 3 */
                ((z->parent)->parent)->Color = Red;     /* CASE 3 */
				if (z->parent != NULL){
					printf("\np of z = %d\n", (z->parent)->data);
				}
                root = LEFT_ROTATE(root, (z->parent)->parent); /* CASE 3 */
                printf("8!\n");
            }
        }
        printf("9!\n");
    }
    printf("WE down!\n");
    root->Color = Black;
    return root;
}

node* LEFT_ROTATE(node *root, node *x)
{
    node *y=NULL;
    display_tree(root);
    printf("left up!\n");
	printf("\n\ndata root = %d, data x = %d\n\n", root-> data, x->data);
	if (x->parent != NULL){
		printf("\np of x = %d\n", (x->parent)->data);
	}
    y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        (y->parent)->left = x;
    y->parent = x->parent;
    if (x->parent == NULL) {
		printf("\ndata x = %d\n", x->data);
		printf("ROOT CHANGE!\n");
        root = y;
    } else {
        if (x == (x->parent)->left)
            (x->parent)->left = y;
        else
            (x->parent)->right = y;
    }
    y->left = x;
    x->parent = y;

    printf("left dwon!\n");
    display_tree(root);
    return root;
}

node* RIGHT_ROTATE(node *root, node *x)
{
    node *y=NULL;

    printf("right up!\n");
	printf("data x = %d\n", x->data);
    y = x->left;
    x->left = y->right;
    if (y->left != NULL)
        (y->parent)->right = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else {
        if (x == (x->parent)->left)
            (x->parent)->left = y;
        else
            (x->parent)->right = y;
    }
    y->right = x;
    x->parent = y;
    printf("right dwon!\n");
    return root;
}
