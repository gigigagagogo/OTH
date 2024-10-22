#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *rep(char *string, char *lhs, char *rhs, int n){
	char *rsub = string;
	do{
		rsub=strstr(rsub, lhs);
		if(rsub == NULL){
			printf("No char match!\n");
			return NULL;
		}
		if(n > 0){
			rsub++;
		}
	}while(n--);
	char *ret = malloc(sizeof(string) + strlen(rhs) - strlen(lhs) + 1);

	if(ret == NULL){
		printf("Memory allocation failed!\n");
		return NULL;
	}

	sprintf(ret,"%.*s%s%.*s",(int)(rsub-string),string,rhs,(int) (strlen(string) - (rsub - string) - strlen(lhs)), rsub + strlen(lhs));

	return ret;

}

int isterminal(char *word){

	while(*word){
		if(isupper(*word++)){
			return 1;
		}
	}
	return 0;

}
