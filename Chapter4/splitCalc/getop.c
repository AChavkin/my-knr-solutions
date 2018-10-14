#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

extern int varkey;
extern double varval;

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-' && c!='$') return c;
	if (c == '$'){
		if('a' <= (s[++i] = c = getch()) && c <= 'z'){
			while (isdigit(s[++i] = c = getch()))
				;
			s[i] = '\0';
			varkey = s[1];
			s[0] = '0';
			s[1] = '0';
			varval = atof(s);
			return SETVAR;
		}
		else {
			ungetch(c);
			return '$';
		}
	}
	if (c == '-'){
		if (isdigit(s[++i] = c = getch()))
			while (isdigit(s[++i] = c = getch()))
				;
		else {
			ungetch(c);
			return '-';
		}
	}
	if (isalpha(c)){
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		ungetch(c);
		if (strlen(s) == 1 && 'a' <= s[0] && s[0] <= 'z') return GETVAR;
		return ALPHA;

	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	ungetch(c);
	return NUMBER;
}