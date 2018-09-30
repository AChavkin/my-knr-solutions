#include <stdio.h>

#define SIZE 50

void escape(char s[], char t[]);

int main(){

	char s[SIZE];
	char t[] = "a	b 	c1 \" \nd";

	escape(s, t);

	printf("%s\n", s);

	return 0;
}

void escape(char s[], char t[]){

	int i,j;
	j=0;

	for(i=0; t[i]!='\0'; ++i){

		switch(t[i]){

			case '\t': s[j]='\\'; s[++j]='t'; break;
			case '\n': s[j]='\\'; s[++j]='n'; break;
			case '\a': s[j]='\\'; s[++j]='a'; break;
			case '\b': s[j]='\\'; s[++j]='b'; break;
			case '\f': s[j]='\\'; s[++j]='f'; break;
			case '\r': s[j]='\\'; s[++j]='r'; break;
			case '\v': s[j]='\\'; s[++j]='v'; break;
			case '\?': s[j]='\\'; s[++j]='\?'; break;
			case '\'': s[j]='\\'; s[++j]='\''; break;
			case '\"': s[j]='\\'; s[++j]='\"'; break;
			default: s[j]=t[i]; break;
		}
		++j;
	}
	s[j]='\0';
}