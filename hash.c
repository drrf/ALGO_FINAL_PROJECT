/*
 *          File: hash.c
 *        Author: Ron F. <>
 * Last Modified: June, 2019
 *         Topic: RBT & Hash table
 * ----------------------------------------------------------------
 */

#include "my_h.h"

int hashInitialize (hash* hash_ptr)
{

	int i = ZERO;
	char str[MAX_WORD];

	strcpy(str, "null");

	for (i = ZERO; i<=HASH_SIZE; i++){
		hash_ptr->h_ptr = hash_ptr->hashArr[i];
		strcpy(hash_ptr->h_ptr, str);
	}

	return 0;
}

int hashFunc1(char word[MAX_WORD])
{
	int hashVal = ZERO;

	hashVal = hashCode(word);
	hashVal = hashVal % HASH_SIZE;
	if(hashVal < ZERO)
		hashVal += HASH_SIZE;

	return hashVal;
}

int hashFunc2(char word[MAX_WORD])
{
	int hashVal = ZERO;

	hashVal = hashCode(word);
	hashVal = hashVal % HASH_SIZE;
	if(hashVal < ZERO)
		hashVal += HASH_SIZE;

	return THREE - hashVal % THREE;	/* step size mush to be PRIME NUM */
}

int hashCode(char word[MAX_WORD])
{
	int i, len = strlen(word), hash_num = ZERO;

	for (i = ZERO; i < len; i++)
		hash_num += (int)word[i];

	return hash_num;
}

int insertHash(hash* hash_ptr, char word[MAX_WORD])
{
	int hashVal = hashFunc1(word);
	int stepSize = hashFunc2(word);
	int def;
	char str[MAX_WORD];

	strcpy(str, "null");
	hash_ptr->h_ptr = hash_ptr->hashArr[hashVal];
	def = strcmp(hash_ptr->h_ptr, str);

	while(def != ZERO)
	{
		hashVal = hashVal + stepSize;
		hashVal = hashVal % HASH_SIZE;
		hash_ptr->h_ptr = hash_ptr->hashArr[hashVal];
		def = strcmp(hash_ptr->h_ptr, str);
	}
	strcpy(hash_ptr->h_ptr, word);

	return 0;
}

int findHash(hash* hash_ptr, char word[MAX_WORD])
{
	int hashVal = hashFunc1(word);
	int stepSize = hashFunc2(word);
	int def1, def2;
	char str[MAX_WORD];

	strcpy(str, "null");
	hash_ptr->h_ptr = hash_ptr->hashArr[hashVal];
	def1 = strcmp(hash_ptr->h_ptr, str);	/* check null */
	def2 = strcmp(hash_ptr->h_ptr, word);	/* check the word */

	while(def1 != ZERO)		/* while not null */
	{
		if (def2 == ZERO)	/* found the serch word */
			return TRUE;
		hashVal = hashVal + stepSize;
		hashVal = hashVal % HASH_SIZE;
		hash_ptr->h_ptr = hash_ptr->hashArr[hashVal];
		def1 = strcmp(hash_ptr->h_ptr, str);
	}
	

	return FALSE;
}
