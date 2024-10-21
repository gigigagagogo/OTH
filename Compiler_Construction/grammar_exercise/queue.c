#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	node_t *prev;
	char *word;
	node_t *next;
} node_t;

int enqueue_word(node_t **head, node_t **tail, char *string) {
	node_t newNode = malloc (sizeof(node_t));
	if(newMode == NULL){
		printf("Error with memory allocation!\n");
		return 1;
	}

	newNode -> word = string;
	newNode -> next = NULL;
	newNode -> prev = *tail;

	if(tail == NULL){
		*head = newNode;
		*tail = newNode;
	}else{
		(*tail) -> next = newNode;
		*tail = newNode;
	}

	return 0;
}

