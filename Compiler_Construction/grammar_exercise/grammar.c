#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grammar {
	char *lhs;
	char *rhs;
} rules;

typedef struct nodeg {
	node_g *prev;
	rules rule;
	node_g *next; 
} node_g;

int generate_rules(node_g **head, node_g **tail){

	while(1){

		rules *newRule = malloc(sizeof(rules));
		if(newRule == NULL){
			printf("Error with memory allocation!\n");
			return 1;
		}

		char string [256];
		printf("Insert left rule or end:\n");
		do{
			scanf("%s", string);
		while(strlen(string) == 0);

		if(strcmp(string,"end") == 0){
			free(newRule);
			return 1;
		}
		newRule -> lhs = strdup(string);

		printf("Insert right rule:\n");
		scanf("%s", string);
		newRule -> rhs = strdup(string);

		if(enqueue_grammar(head, tail, newRule) != 0){
			printf("Error with grammar rule enqueue!\n");
			return ;
		}

		free(newRule -> lhs);
		free(newRule -> rhs);
		free(newRule);

	}
	 return 0;

}

int enqueue_grammar(node_g **head, node_g **tail, rules grule){
	node_g *newNode = malloc(sizeof(node_g));

	if(newMode == NULL){
		printf("Error with memory allocation!\n");
		return 1;
	}

	newNode -> rule = grule;
	newNode -> next = NULL;
	newNode -> prev = *tail;

	if (tail == NULL){
		*tail = newNode;
		*head = newNode;
	}else{
		(*tail) -> next = newNode;
		*tail = newNode;
	}

	return 0;
}

char *dequeue(node_g pop_rule){
	return (pop_rule -> rule.rhs);
}
