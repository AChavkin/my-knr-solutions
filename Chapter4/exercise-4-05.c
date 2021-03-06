#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'
#define ALPHA '1'

int getop(char s[]);
double mathfunc(char s[]);
void push(double f);
double pop(void);
void peek(void);
void duplicate(void);
void swap(void);
void clear(void);
int getch(void);
void ungetch(int c);

double op2;

int main()
{
	int type;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch (type) {
			case NUMBER: push(atof(s)); break;
			case ALPHA: push(mathfunc(s)); break;
			case '+': push(pop() + pop()); break;
			case '*': push(pop() * pop()); break;
			case '-': op2 = pop(); push(pop() - op2); break;
			case '/': op2 = pop(); 
					  if(op2 != 0.0) push(pop() / op2);
					  else printf("Error: zero divisor \n"); break;
			case '%': op2 = pop(); 
					  if(op2 != 0.0) push(fmod(pop(), op2));
					  else printf("Error: zero divisor \n"); break;
			case '\n': printf("\t%.8g\n", pop()); break;
			default: printf("Error: unknown command\n"); break;
		}
	}
	return 0;
}

double mathfunc(char s[])
{
	if (strcmp(s, "sin") == 0) return sin(pop());
	else if (strcmp(s, "asin") == 0) return asin(pop());
	else if (strcmp(s, "cos") == 0) return cos(pop());
	else if (strcmp(s, "acos") == 0) return acos(pop());
	else if (strcmp(s, "tan") == 0) return tan(pop());
	else if (strcmp(s, "atan") == 0) return atan(pop());
	else if (strcmp(s, "cosh") == 0) return cosh(pop());
	else if (strcmp(s, "sinh") == 0) return sinh(pop());
	else if (strcmp(s, "tanh") == 0) return tanh(pop());
	else if (strcmp(s, "log") == 0) return log(pop());
	else if (strcmp(s, "sqrt") == 0) return sqrt(pop());
	else if (strcmp(s, "exp") == 0) return exp(pop());
	else if (strcmp(s, "ceil") == 0) return ceil(pop());
	else if (strcmp(s, "floor") == 0) return floor(pop());
	else if (strcmp(s, "abs") == 0) return fabs(pop());
	else if (strcmp(s, "pow") == 0) {
		op2 = pop();
		return(pow(pop(), op2));
	}
	else {
		printf("Error: function not recognized.\n");
		clear();
		return 0.0;
	}
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
		printf("Error: stack empty.\n");
		return 0.0;
	}
}

void peek(void)
{
	if (sp > 0) printf("%g\n", val[sp-1]);
	else printf("Error: stack empty.\n");
}

void duplicate(void)
{
	if (sp > 0 && sp < MAXVAL) {
		val[sp] = val[sp-1];
		sp++;
	}
	/* decide which error to print based on the value of sp: */
	else (sp) ? printf("Error: stack full. "
		"Can't duplicate %g\n", val[sp-2]) : \
		printf("Error: stack empty.\n");
}

void swap(void)
{
	double temp;
	if (sp > 1){
		temp = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = temp;
	} 
	else printf("Error: Need at least 2 values in stack.\n");
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
	if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-') return c;
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
		if (c != EOF) ungetch(c);
		return ALPHA;

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