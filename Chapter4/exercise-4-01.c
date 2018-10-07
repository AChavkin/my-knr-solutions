#include <stdio.h>

#define MAXLINE 1000

int strrindex(char s[], char t[]);

int main(){

	char s[] = "If only the world was a kinder place. "
	"Alas, the caretakers of the world are not kind.";
	char t[] = "world";
	char u[] = "gothic";

	printf("%d\n", strrindex(s,u));
	printf("%d\n", strrindex(s,t));

	return 0;
}

int strrindex(char s[], char t[]){

	// Return the index of the last (rightmost) match of t in s.

	int i, j, k, match;
	match=-1;

	for (i=0; s[i]!='\0'; i++){
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k>0 && t[k]=='\0') match=i;
	}
	return match;
}