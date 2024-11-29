#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enqueue_word(node_t **head, node_t **tail, char *string) {
  node_t *newNode = malloc(sizeof(node_t));
  if (newNode == NULL) {
    printf("Error with memory allocation!\n");
    return 1;
  }

  newNode->word = strdup(string);
  newNode->next = NULL;
  newNode->prev = *tail;

  if (*tail == NULL) {
    *tail = newNode;
    *head = newNode;
  } else {
    (*tail)->next = newNode;
    *tail = newNode;
  }

  return 0;
}

char *dequeue_word(node_t **head) {

  if (*head == NULL) {
    return NULL;
  }

  // node_t *temp = *head;
  // char *word = temp->word;

  // *head = (*head)->next;
  // if (*head != NULL) {
  //   (*head)->prev = NULL;
  // }
  // free(temp);

  char *word = (*head)->word;
  *head = (*head)->next;
  free((*head)->prev);
  (*head)->prev = NULL;
  return word;
}

int emptyqueue(node_t **head) { return (*head == NULL); }