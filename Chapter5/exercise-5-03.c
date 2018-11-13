#include <stdio.h>

#define SIZE 100

void mystrcat(char *s, char *t);

int main()
{
	char s[SIZE] = "cool";
	char t[SIZE] = "thing";
	mystrcat(s, t);
	printf("%s\n", s);
	printf("%s\n", t);
	return 0;
}

void mystrcat(char *s, char *t)
{
	while(*s != '\0') s++;
	while((*(s++) = *(t++)) != '\0') ;
}