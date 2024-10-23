#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char *rep(char *string, char *lhs, char *rhs){
	char *pos = string;
	char *ret;
	
	while(1){
		pos = strstr(pos, lhs);
		
		if(pos == NULL){
			printf("No more char match!\n");
			break;
		}
		ret = (char *)malloc(strlen(pos) + strlen(rhs) - strlen(lhs) + 1);
		if(ret == NULL){
			printf("Memory allocation failed!\n");
			return NULL;
		}
		sprintf(ret,"%.*s%s%.*s",(int)(pos-string),string,rhs,(int) (strlen(string) - (pos - string) - strlen(lhs)), pos + strlen(lhs));
	}
	return ret;
}
/*

char *rep(char *string, char *lhs, char *rhs) {
    char *pos = string;
    char *ret = NULL;
    char *newStr;
    int lenDiff = strlen(rhs) - strlen(lhs);

    // Ciclo che esegue le sostituzioni finché ci sono match
    while ((pos = strstr(pos, lhs)) != NULL) {
        // Calcola la lunghezza della nuova stringa
        newStr = malloc(strlen(string) + lenDiff + 1);
        if (newStr == NULL) {
            printf("Memory allocation failed!\n");
            return NULL;
        }

        // Costruisce la nuova stringa
        strncpy(newStr, string, pos - string);  // Copia la parte prima del match
        newStr[pos - string] = '\0';  // Termina la stringa prima del match
        strcat(newStr, rhs);  // Aggiungi la parte sostituita
        strcat(newStr, pos + strlen(lhs));  // Aggiungi il resto della stringa dopo il match

        free(ret);  // Libera la memoria precedente
        ret = newStr;  // Assegna la nuova stringa come risultato

        // Sposta `pos` oltre il match appena sostituito
        pos += strlen(lhs);
    }

    if (ret == NULL) {
        // Nessuna sostituzione trovata, restituisce una copia della stringa originale
        ret = strdup(string);
    }
    printf("Prova rep\n");
    return ret;
}
*/

int isterminal(char *word){
	while(*word){
		if(isupper(*word++)){
			return 1;
		}
	}
	return 0;
}
