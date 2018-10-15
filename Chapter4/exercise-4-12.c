#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 100

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{

	char test[SIZE];
	itoa(-2134567, test);
	printf("%s\n", test);
	itoa(-2134567, test);
	printf("%s\n", test);
	itoa(-2134567, test);
	printf("%s\n", test);
	return 0;
}

void itoa(int n, char s[])
{	
	static int i = 0;
	int sign;

	sign = n;
	
	s[i++] = abs(n % 10) + '0';
	if (n /= 10) {
		itoa(n, s);
		--i;
	}
	else {
		if (sign < 0) s[i++] = '-';
		s[i] = '\0';
		reverse(s);
		--i;
		--i;
	}
}

void reverse(char s[])
{
	int c, i, j;

	for (i=0, j=strlen(s)-1; i<j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}