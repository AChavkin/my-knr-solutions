#include <stdio.h>

/* I used an if so that I could re-declare z as different
types/ different namespace if the macro is used multiple 
times within the same block */
#define swap(t, x, y) if (1) {t z = x; x = y; y = z;}

int main()
{
	int a = 0;
	int b = 1;

	printf("%d %d\n", a, b);
	swap(int, a, b)
	printf("%d %d\n", a, b);

	char c = 'a';
	char d = 'b';

	printf("%c %c\n", c, d);
	swap(char, c, d)
	printf("%c %c\n", c, d);

	return 0;
}