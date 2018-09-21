#include <stdio.h>

int any(char s1[], char s2[]);

int main(){

	printf("%d", any("tish","hat"));

	return 0;
}

int any(char s1[], char s2[]){

	int i,j,first;

	first=-1;

	for (i=0; s2[i]!='\0'; ++i){
		for (j=0; s1[j]!='\0'; ++j){
			if (s2[i]==s1[j]){
				if (first==-1 || first>j) first=j;
			}
		}
	}
	return first;
}