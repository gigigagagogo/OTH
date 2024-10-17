#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct grammar_rule{

	char *lft_rule;
	char *rgh_rule;

};

int main(void){

	char input[256];
	struct grammar_rule *rules = NULL;
	int nrules = 0;

	while(1){
		printf("Left rule or end: ");

		do{
			scanf("%s", input);
		}while(strlen(input) == 0);

		if(strcmp(input,"end") == 0){
			break;
		}

		struct grammar_rule *temp = realloc(rules, (nrules+1) * sizeof(struct grammar_rule));
		if(temp == NULL){
			printf("Problem with the memory allocation");
			free(rules);
			return 1;
		}

		rules = temp;
		rules[nrules].lft_rule=strdup(input);

		printf("Right rule: ");
		scanf("%s", input);
		rules[nrules].rgh_rule = strdup(input);
		nrules++;
	}

	printf("Rules list:\n");
 
	for(int i = 0; i < nrules; i++){
		printf("{%s} -> {%s}\n", rules[i].lft_rule, rules[i].rgh_rule);
	}

	free(rules);

	return 0;

}

