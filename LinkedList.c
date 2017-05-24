/*
 * linkedList.c
 *
 *  Created on: 22.05.2017
 *      Author: Jasper Reichardt
 */

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

/********** GLOBALS *******************************/
#define OK 0
#define ERROR -1

/********** STRUCT AND TYPES DEFINTIONS ***********/
/* a node with key, data and reference to next node*/
typedef struct Node {
	int key;
	char string[1024];
	struct Node *next;  // pointer to next node
} Node;

/* the actual linked list: ref to first and last Node, size attribute */
typedef struct LinkedList {
	struct Node *first;
	struct Node *last;
	int size;
} LinkedList;

/********** FUNCTION HEADERS **********************/
LinkedList* init_list();
void insert_end(LinkedList *list, int key, char string[]);
void insert_beginning(LinkedList *list, int key, char string[]);
int remove_end(LinkedList *list);
int remove_beginning(LinkedList *list);
int print_list(LinkedList *list);
void free_list(LinkedList *list);
char * get_string(LinkedList *list, int key);

/*********** FUNCTION DEFINITIONS ***************/

/**
 * init_list Returns an appropriately (for an empty list) initialized struct List
 *
 * @return LinkedList * 		..ptr to the newly initialized list
 */
LinkedList * init_list() {
	printf("initializing list...\n");

	LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));

	list->first = NULL;
	list->last = NULL;
	list->size = 0;

	return list;
}

/**
 * Given a List, a key and a string adds a Node containing this
 * information at the end of the list
 *
 * @param list		LinkedList *    ..ptr to LinkedList
 * @param key       int				.. key of the Node to be inserted
 * @param string    char[]			.. the string of the Node to be inserted
 */
void insert_end(LinkedList *list, int key, char string[]) {
	printf("----------------------\n");

	list->size++;                    // increment size of list

	// intialize the new Node
	Node* newN = (Node*) malloc(sizeof(Node));
	newN->key = key;
	strcpy(newN->string, string);
	newN->next = NULL;

	Node* oldLast = list->last;      // get the old last
	oldLast->next = newN;          // make new Node the next Node for oldlast
	list->last = newN;              // set the new last  in the list

	printf("new Node(%p) at end: %d '%s' %p \n", newN, newN->key, newN->string,newN->next);
}

/**
 * Given a List, a key and a string adds a Node, containing
 * this information at the beginning of the list
 *
 * @param list		LinkedList *    ..ptr to LinkedList
 * @param key		int				.. key of the Node to be inserted
 * @param string	char[]			.. the string of the Node to be inserted
 */
void insert_beginning(LinkedList *list, int key, char string[]) {
	printf("----------------------\n");

	list->size++;                    // increment size of list
	Node* oldFirst = list->first;    //get the old first node

	/* intialize the new Node */
	Node* newN = (Node*) malloc(sizeof(Node));
	newN->key = key;
	strcpy(newN->string, string);
	newN->next = oldFirst;

	list->first = newN;              // set the new first

	/* special case: if list size == 1, then this new one is also the last one */
	if (list->size == 1)
		list->last = newN;

	printf("new Node(%p) at beginning: %d '%s' %p \n", newN, newN->key,newN->string, newN->next);
}

/**
 * Removes the first Node from the list
 *
 * @param list		LinkedList *		.. ptr to the List
 *
 * @return OK | ERROR
 */
int remove_beginning(LinkedList *list) {
	printf("----------------------\n");

	if (list->size <= 0)
		return ERROR;

	list->size--;

	Node * oldFirst = list->first;

	printf("delete Node(%p) at beginning: '%d' '%s' '%p' \n", oldFirst,oldFirst->key, oldFirst->string, oldFirst->next);

	free(list->first); 			//free it
	list->first = oldFirst->next;
	oldFirst = NULL;

	return OK;
}

/**
 * Removes the last Node from the list.
 *
 * @param list		LinkedList *		.. ptr to the List
 *
 * @return OK | ERROR
 */
int remove_end(LinkedList *list) {
	printf("----------------------\n");

	/* special case #1 */
	if (list->size <= 0)
		return ERROR;

	/* special case #2 */
	if (list->size == 1) {
		free(list->first);
		list->first = NULL;
		list->last = NULL;
		return OK;
	}

	printf("delete Node(%p) at end: '%d' '%s' '%p' \n", list->last,list->last->key, list->last->string, list->last->next);

	list->size--;           // decrement list size
	Node * startNode = list->first;

	/* find the new last node (the one before the old last one); list->size >= 2 at this point!*/
	Node * newLast = startNode;
	while (newLast->next->next != NULL) {
		newLast = newLast->next;
	}

	free(newLast->next); 	//free it
	newLast->next = NULL;  	//set to NULL to denote new end of list
	list->last = newLast; 	// set the new list->last

	return OK;
}

/**
 * Given a List prints all key/string pairs contained in the list to
 * the screen
 *
 * @param list		LinkedList *		.. ptr to the List
 *
 * @return	OK | ERROR
 */
int print_list(LinkedList *list) {

	printf("----------------------\n");

	if (list->size <= 0)
		return ERROR;

	printf("List.size = %d \n", list->size);

	Node *startN = list->first;  //get first

	/* iterate through list and print contents */
	do {
		printf("Node#%d.string = '%s', .next = '%p' \n", startN->key,startN->string, startN->next);
		startN = startN->next;
	} while (startN != NULL);

	return OK;
}

/**
 * Given a List, frees all memory associated with this list.
 *
 * @param list		LinkedList *		..ptr to the list
 */
void free_list(LinkedList *list) {
	printf("----------------------\n");
	printf("freeing list...\n");

	if (list != NULL && list->size > 0) {
		Node * startN = list->first;
		Node * temp = list->first;

		do {
			free(temp);
			startN = startN->next;
			temp = startN;
		} while (startN != NULL);

		free(list);
	}
}

/**
 * Given a List and a key, iterates through the whole List and returns
 * the string of the first node which contains the key
 *
 * @param list		LinkedList *		..ptr to the list
 * @param key		int					.. the key of the Node to get the String from
 *
 * @return OK | ERROR
 */
char * get_string(LinkedList *list, int key) {
	printf("----------------------\n");

	Node *startN = list->first;  //get first

	/* iterate through list and find Node where node->key == key */
	while (startN->next != NULL) {
		if (startN->key == key)
			return startN->string;
		else
			startN = startN->next;
	}

	return NULL;
}

/*************** MAIN **************/
int main(void) {

	LinkedList *list = init_list();

	insert_beginning(list, 1, "im the first");
	insert_end(list, 2, "im the second");
	insert_end(list, 3, "im the third");
	insert_end(list, 4, "forth here");

	print_list(list);
	remove_end(list);
	print_list(list);
	remove_beginning(list);
	print_list(list);
	remove_end(list);
	print_list(list);
	printf("string at node with key %d = '%s' \n",2,get_string(list, 2));
	free_list(list);

	return OK;
}
