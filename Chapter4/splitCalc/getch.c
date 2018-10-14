#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
	else if (c != EOF) buf[bufp++] = c;
}

void ungets (char s[])
{
	int i = 0;

	/* ungets should do its own buf check so that partial lines 
	of input aren't fragmented */
	if (bufp + strlen(s) >= BUFSIZE) printf("ungets: too many characters\n");
	else{
		for (i=0; i<strlen(s); ++i) ungetch(s[i]);
	}
}