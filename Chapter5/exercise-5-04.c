#include <stdio.h>

#define SIZE 100

int strend(char *s, char *t);

int main()
{
	char s[SIZE] = "something";
	char t[SIZE] = "hing";
	char u[SIZE] = "bhing";
	printf("%d\n", strend(s, t));
	printf("%d\n", strend(s, u));
	return 0;
}

int strend(char *s, char *t)
{
	int len = 0;
	while(*t){
		t++;
		len++;
	}
	while(*s) s++;
	for(; (len>0 && (*--s == *--t)); len--) ;
	if (len) return 0;
	return 1;
}