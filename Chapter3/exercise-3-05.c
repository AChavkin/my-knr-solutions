#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 100

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(){

	char s[SIZE];
	char t[SIZE];
	char u[SIZE];
	itob(INT_MAX-UINT_MAX, t, 16);
	itob(3748234, s, 21);
	itob(46831648, u, 16);
	printf("%s\n", u);
	printf("%s\n", s);
	printf("%s\n", t);
	return 0;
}

void itob(int n, char s[], int b){

	int i, sign, mod;
	i = mod = 0;

	sign = n;
	do{
		if (b <=10) s[i++] = abs(n % b) + '0';
		else{
			if ((mod = abs(n%b)) >= 10) s[i++] = mod + ('A' - 10);
			else s[i++] = mod + '0';
		}
	} while (n /= b);
	if (sign < 0) s[i++] = '-';
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