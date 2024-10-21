#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grammar.h"
#include "queue.h"

int main(void){
	node_g *head = NULL;
	node_g *tail = NULL;

	if(generate_rules(&head,&tail) != 0){
		printf("Error with rules generation!\n");
		return 1;
	}

	node_g *current = head;
    	while (current != NULL) {
        	printf("{%s -> %s\n}", current->rule.lhs, current->rule.rhs);
       		if(enqueue_word(current) != 0){
			printf("Error with word enqueue!\n");
			return ;
		}
		current = current->next;
    	}

	return 0;

}
