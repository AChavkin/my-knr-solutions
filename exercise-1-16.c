#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(){

	int max, len;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while ((len=getline_other(line, MAXLINE)) > 0){
		if (len > max){
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) printf("%d %s", max, longest);

	return 0;
}

int _getline(char s[], int lim){

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

void copy(char to[], char from[]){
	int i;

	i=0;
	while ((to[i] = from[i])!= '\0')
		++i;
}