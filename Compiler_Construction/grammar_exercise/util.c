#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char *rep (char *subject, char *lhs, char *rhs, int n) {
  char *ptr = subject;

  // Find n'th occurrence
  do {
    ptr = strstr(ptr, lhs);
    if (!ptr)
      return NULL;
    if (n > 0)
      ptr++;
  } while (n--);

  char *ret = malloc(strlen(subject)+strlen(rhs)-strlen(lhs)+1);

  if(ret == NULL){
       	printf("Memory allocation error!\n");
  }
		

  // Build the target word here
  sprintf(ret, "%.*s%s%.*s",
      (int)(ptr-subject), subject,
      rhs,
      (int)(strlen(subject)-(ptr-subject)-strlen(lhs)), ptr+strlen(lhs));

  // and return it
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
