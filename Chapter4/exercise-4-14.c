#include <stdio.h>

/* Braces used to create block with new namespace for z (diff types) */
#define swap(t, x, y) {t z = x; x = y; y = z;}

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