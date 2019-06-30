/*
 *          File: hash_others.c
 *        Author: Ron F. <>
 * Last Modified: June, 2019
 *         Topic: RBT & Hash table
 * ----------------------------------------------------------------
 */

#include "my_h.h"

int isPrime(int num)
{
	int i=ZERO;

	for (i = TWO; i*i <= num; i++){
		if (num % i == ZERO)
			return FALSE;
	}
	return TRUE;
}

int getNextPrime(int minNumber)
{
	int i=ZERO;

	for (i=minNumber; ; i++)
		if(isPrime(i))
			return i;
}

int printHashTable (hash* hash_ptr)
{
	int i = ZERO, def;
	char str[MAX_WORD];

	strcpy(str, "null");

	printf("START printHashTable: \n");
	for (i = ZERO; i<HASH_SIZE; i++){
		hash_ptr->h_ptr = hash_ptr->hashArr[i];
		def = strcmp(hash_ptr->h_ptr, str);
		if (def != ZERO )
			printf("%s!\n", hash_ptr->h_ptr);
		else
			printf("**\n");
	}
	return 0;
}
