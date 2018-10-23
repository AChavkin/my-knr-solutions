#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 100

int getch(void);
void ungetch(int c);
int getint(int *pn);

int main()
{
	int n, a[SIZE];
	char b;

	for (n = 0; n < SIZE && getint(&a[n]) != EOF; n++)
		;
	for (n = 0; n < SIZE; n++) printf("%d\n", a[n]);
	return 0;
}

int getint(int *pn)
{
	int c, d, sign;
	/* We need a mechanism to track a solo - or + between calls
	to still have the proper buffer ordering in ungetch() for
	any other function that wants to use it, and not just move
	the sign to the digit because spaces are skipped */
	static int solo = 0;

	if (solo) {
		solo = 0;
		return 0;
	}
	while (isspace(c=getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-'){
		d = c;
		if (!isdigit(c=getch())){
			ungetch(d);
			ungetch(c);
			++solo;
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF) ungetch(c);
	return c;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
	else buf[bufp++] = c;
}