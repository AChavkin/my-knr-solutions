#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'

int getop(char s[]);
void push(double f);
double pop(void);
void peek(void);
void duplicate(void);
void swap(void);
void clear(void);
int getch(void);
void ungetch(int c);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch (type) {
			case NUMBER: push(atof(s)); break;
			case '+': push(pop() + pop()); break;
			case '*': push(pop() * pop()); break;
			case '-': op2 = pop(); push(pop() - op2); break;
			case '/': op2 = pop(); 
					  if(op2 != 0.0) push(pop() / op2);
					  else printf("Error: zero divisor \n"); break;
			case '%': op2 = pop(); 
					  if(op2 != 0.0) push((int)pop() % (int)op2);
					  else printf("Error: zero divisor \n"); break;
			case '\n': printf("\t%.8g\n", pop()); break;
			default: printf("Error: unknown command\n"); break;
		}
	}
	return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL) val[sp++] = f;
	else printf("Error: stack full. Can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0) return val[--sp];
	else{
		printf("Error: stack empty.");
		return 0.0;
	}
}

void peek(void)
{
	if (sp > 0) printf("%g\n", val[sp-1]);
	else printf("Error: stack empty.");
}

void duplicate(void)
{
	if (sp > 0 && sp < MAXVAL) val[sp++] = val[sp-1];
	/* decide which error to print based on the value of sp: */
	else (sp) ? printf("Error: stack full. "
		"Can't duplicate %g\n", val[sp-2]) : \
		printf("Error: stack empty.");
}

void swap(void)
{
	double temp;
	if (sp > 1){
		temp = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = temp;
	} 
	else printf("Error: Need at least 2 values in stack.");
}

void clear(void)
{
	int i;
	for (i = 0; i < sp; i++) val[i] = '\0';
	sp = 0;
}

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-') return c;
	if (c == '-'){
		if (isdigit(s[++i] = c = getch()))
			while (isdigit(s[++i] = c = getch()))
				;
		else {
			ungetch(c);
			return '-';
		}
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF) ungetch(c);
	return NUMBER;
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