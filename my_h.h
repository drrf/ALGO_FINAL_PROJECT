/*
 *          File: my_h.h
 *        Author: Ron F. <>
 * Last Modified: June, 2019
 *         Topic: RBT & Hash table
 * ----------------------------------------------------------------
 */
/* INCLUDE */
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

/* DEFINE MIN-MAX LENGTH */
#define MAX_FILES 3         /* MAX FILE THAT PROGRAM CAN INPUT IN 1 RUN */
#define MAX_WORD 33         /* MAX WORD LENGTH & IN ONE LINE */
#define MAX_LINE 512        /* MAX LINE LENGTH & LINES IN FILES */
#define MAX_CODE 99999	    /* MAX CODE IN ONE .AS FILE */

/* DEFINE HASH */
#define HASH_SIZE 2239		/* HASH_SIZE=nextPRIME(n^1.123) */	
#define HASH_PRIME 2237		/* PRIME NUMBER FOR HASH STEPSIZE */

/* SIMPLE THE CODE FROM NUNBERS */
enum NUM_ID { ZERO, ONE, TWO, THREE, FOUR, FIVE };

/* ColorType Red = 0, Black = 1 */
typedef enum ColorType {
    Red, Black
} ColorType;

/* NODE OF RBT */
typedef struct node
{
    ColorType Color;		/* the color of this node */
    int data;				/* key number, by enter order */
    char word[MAX_WORD];	/* the word that we need to check */
    struct node* left;		/* child left */
    struct node* right;		/* child right */
    struct node* parent;	/* parent node */
} node;

/* THE HASH TABLE */
typedef struct hash
{
    char hashArr[HASH_SIZE][MAX_WORD];	/* the cell of the hash */
    char* h_ptr;						/* pointer to the cell hash */
} hash;

/* FUNC on main.c */
void Print_intro();
void Print_finalRBT();
void Print_outro();

/* FUNC on file_to_x.c */
int File_to_Hash (char* , hash* );
node* File_to_RBT (char* , node* );

/* FUNC on rbt.c */
node* create_node(int , char[] );
node* RB_INSERT(node *, int , char []);
node* RB_INSERT_FIXUP(node *, node *);
node* LEFT_ROTATE(node *, node *);
node* RIGHT_ROTATE(node *, node *);

/* FUNC on hash.c */
int hashFunc1(char []);
int hashFunc2(char []);
int hashCode(char []);
int hashInitialize (hash* );
int insertHash(hash* , char []);
int findHash(hash* , char []);

/* FUNC on check.c */
int checkRBT (hash* , node *);
