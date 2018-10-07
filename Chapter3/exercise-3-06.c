#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 100

void itoa(int n, char s[], int width);
void reverse(char s[]);

int main(){

	char s[SIZE];
	char t[SIZE];
	itoa(INT_MAX-UINT_MAX, s, 5);
	itoa(3748234, t, 10);
	printf("%s\n", s);
	printf("%s\n", t);
	return 0;
}

void itoa(int n, char s[], int width){

	int i, sign;
	i = 0;

	if ((sign = n) < 0) n = -n;
	do{
		s[i++] = abs(n % 10) + '0';
		printf("CURRENT N: %d\t CURRENT S: %s\n", n, s);
	} while (n /= 10);
	if (sign < 0) s[i++] = '-';
	while (i < width) s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){

	int c, i, j;

	for (i=0, j=strlen(s)-1; i<j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}