/*
 *          File: myas.h
 *        Author: Ron F. <>
 * Last Modified: April 8, 2018
 *         Topic: RBT & Hash table
 * ----------------------------------------------------------------
 */
/* myas.h */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* FLAGS */
#define EMPTY_AND_BLOCK -9999
#define ERR_NUMBER -999
#define EMPTY 0
#define FALSE 0
#define TRUE 1
#define FIRST 1

/* DEFINE MAX LENGTH */
#define MAX_FILES 3         /* MAX FILE THAT PROGRAM CAN INPUT IN 1 RUN */
#define MAX_WORD 99         /* MAX WORD LENGTH & IN ONE LINE */
#define MAX_LINE 512        /* MAX LINE LENGTH & LINES IN FILES */
#define MAX_CODE 99999	    /* MAX CODE IN ONE .AS FILE */

/* SIMPLE THE CODE FROM NUNBERS */
enum NUM_ID { ZERO, ONE, TWO, THREE, FOUR, FIVE };

/* MY TYPEDEF */
typedef enum ColorType {
    Red, Black
} ColorType;

typedef struct node
{
    ColorType Color;
    int data;
    char word[MAX_WORD];
    struct node* left;
    struct node* right;
    struct node* parent;
} node;

typedef int (*comparer)(int, int);

/* FUNC on main.c */
void Print_intro();

/* FUNC on file_to_x.c */
int File_to_Hash (char* );
int File_to_RBT (char* , node*);

/* FUNC on rbt.c */
int compare(int ,int );
node* create_node(int , char[] );
node* insert_node(node *, comparer , int , char[] );
node* change_root(node *, int , char[] );
void display_tree(node* );
node* RB_INSERT(node *, int , char []);
node* RB_INSERT_FIXUP(node *, node *);
node* LEFT_ROTATE(node *, node *);
node* RIGHT_ROTATE(node *, node *);

/* FUNC on hash.c */