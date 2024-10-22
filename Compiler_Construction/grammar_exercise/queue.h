#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct node {
    struct node *prev;
    char *word;
    struct node *next;
} node_t;

int enqueue_word(node_t **head, node_t **tail, char *word);
char *dequeue_word(node_t **head);
int emptyqueue(node_t **head, node_t **tail);


#endif /* _QUEUE_H */
