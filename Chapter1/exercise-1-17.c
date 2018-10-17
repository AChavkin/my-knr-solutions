#include <stdio.h>
#define MAXLINE 1000
#define PRINTFLOOR 80

int getline_other(char line[], int maxline);
void copy(char to[], char from[]);

int main(){

	int len;
	char line[MAXLINE];

	while ((len=getline_other(line, MAXLINE)) > 0)
		if (len >= PRINTFLOOR) printf("%s",line);

	return 0;
}

int getline_other(char s[], int lim){

	int c, i;

	for (i=0;(c=getchar()) != EOF && c!='\n'; ++i)
		if (i<lim-1) s[i]=c;
	if (i < lim-1 && c == '\n'){
		s[i]=c;
		++i;
		s[i]='\0';
	}
	else s[lim-1]='\0';
	return i;
}