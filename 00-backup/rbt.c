/*
 *          File: rbt.c
 *        Author: Ron F. <>
 * Last Modified: June, 2019
 *         Topic: RBT & Hash table
 * ----------------------------------------------------------------
 */

#include "my_h.h"

/* compare two integers */
int compare(int left,int right)
{
    if(left > right)
        return 1;
    if(left < right)
        return -1;
    return 0;
}

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

/* change the root node */
node* change_root(node *root, int data, char cp_word[MAX_WORD])
{
    if(root == NULL)
    {
        printf("Root is null, create new node!\n");
        root = create_node(data, cp_word);
    } else {
        root->data = data;
    }
    return root;
}

/* insert a new node into the BST */
node* insert_node(node *root, comparer compare, int data, char cp_word[MAX_WORD])
{
    if(root == NULL)
    {
        root = create_node(data, cp_word);
        root->Color = Black;
    }
    else
    {
        int is_left  = 0;
        int r        = 0;
        node* cursor = root;
        node* prev   = NULL;
 
        while(cursor != NULL)
        {
            r = compare(data,cursor->data);
            prev = cursor;
            if(r < 0)
            {
                is_left = 1;
                cursor = cursor->left;
            }
            else if(r > 0)
            {
                is_left = 0;
                cursor = cursor->right;
            }
 
        }
        if(is_left)
            prev->left = create_node(data, cp_word);
        else
            prev->right = create_node(data, cp_word);
 
    }
    return root;
}

/* Recursively display tree or subtree */
void display_tree(node* nd)
{
    if (nd == NULL)
        return;
    /* display node data */
    printf("%d",nd->data);
    if(nd->left != NULL)
        printf("(L:%d)",nd->left->data);
    if(nd->right != NULL)
        printf("(R:%d)",nd->right->data);
    printf("\n");
    if (nd->Color == Red)
        printf("RED, ");
    else
        printf("BLACK, ");

    printf("%s\n",nd->word);
 
    display_tree(nd->left);
    display_tree(nd->right);
}