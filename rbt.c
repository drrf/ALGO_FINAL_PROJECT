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

    if(new_node == NULL)	/* malloc ERROR */
    {
        fprintf (stderr, "Out of memory!!! (create_node)\n");
        exit(1);
    }
    new_node->data = data;              /* copy the data to the node */
    new_node->Color = Red;              /* ALWAYS new node are red */
    strcpy(new_node->word, cp_word);    /* copy the word to the node */
    new_node->left = NULL;				/* make node.left == NULL*/
    new_node->right = NULL;   			/* make node.right == NULL*/
    return new_node;
}

/* insert node to RBT -> by the book */
node* RB_INSERT(node *root, int data, char cp_word[MAX_WORD])
{
    node *z = create_node(data, cp_word);
    node *y=NULL, *x = root;
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
    root = RB_INSERT_FIXUP(root,z);
    return root;
}

/* insert fixup node in RBT -> by the book */
node* RB_INSERT_FIXUP(node *root, node *z)
{
    node *y=NULL;
    while (z != NULL && z->parent != NULL && (z->parent)->Color==Red)
    {
        if(z->parent == ((z->parent)->parent)->left){
            y = ((z->parent)->parent)->right;
            if(y->Color==Red){
                (z->parent)->Color = Black;                 /* CASE L1 */
                y->Color = Black;                           /* CASE L1 */
                ((z->parent)->parent)->Color = Red;         /* CASE L1 */
                z = (z->parent)->parent;                    /* CASE L1 */
            } else {
                if (z == (z->parent)->right){
                    z = z->parent;                          /* CASE L2 */
                    root = LEFT_ROTATE(root, z);            /* CASE L2 */
                }
                (z->parent)->Color = Black;                 /* CASE L3 */
                ((z->parent)->parent)->Color = Red;         /* CASE L3 */
                root = RIGHT_ROTATE(root, (z->parent)->parent);    /* CASE L3 */
            }
        } else { /* if (z->parent == z->parent->parent->right) */
            y = ((z->parent)->parent)->left;
            if (y != NULL && y->Color == Red)
            {
                (z->parent)->Color = Black;             /* CASE R1 */
                y->Color = Black;                       /* CASE R1 */
                ((z->parent)->parent)->Color = Red;     /* CASE R1 */
                z = (z->parent)->parent;                /* CASE R1 */
            } else {
                if (z == (z->parent)->left){
                    z = z->parent;                      /* CASE R2 */
                    root = RIGHT_ROTATE(root, z);       /* CASE R2 */
                }
                (z->parent)->Color = Black;             /* CASE R3 */
                ((z->parent)->parent)->Color = Red;     /* CASE R3 */
                root = LEFT_ROTATE(root, (z->parent)->parent); /* CASE R3 */
            }
        }
    }
    root->Color = Black;
    return root;
}

/* rotate left -> by the book */
node* LEFT_ROTATE(node *root, node *x)
{
    node *y=x->right;  
    x->right = y->left;
	if (x->right != NULL)
        x->right->parent = x;	
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if (x == (x->parent)->left) {
            (x->parent)->left = y;
    } else {
            (x->parent)->right = y;
    }
    y->left = x;
    x->parent = y;
    return root;
}

/* rotate right -> by the book */
node* RIGHT_ROTATE(node *root, node *x)
{
    node *y=x->left;
    y->left = x->right;
    if (x->right != NULL)
        (x->parent)->right = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        root = x;
    else if (x == (x->parent)->left){
    	(y->parent)->left = x;
    } else {
    	(y->parent)->right = x;
    }
    x->right = y;
    y->parent = x;
    return root;
}
