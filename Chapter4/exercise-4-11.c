#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMVARS 26
#define NUMBER '0'
#define ALPHA '1'
#define GETVAR '2'
#define SETVAR '3'

int getop(char s[]);
double mathfunc(char s[]);
void push(double f);
double pop(void);
void peek(void);
void duplicate(void);
void swap(void);
void clear(void);
double getvar(int c);
void setvar(int varkey, double varval);

double op2;
double variables[NUMVARS];
int status[NUMVARS];
int varkey = 0;
double varval = 0.0;
double recent = 0.0;

int main()
{
	int type;
	char s[MAXOP];

	for (type = 0; type < NUMVARS; type++) status[type] = 0;

	while((type = getop(s)) != EOF){
		switch (type) {
			case NUMBER: push(atof(s)); break;
			case ALPHA: push(mathfunc(s)); break;
			case GETVAR: push(getvar(s[0])); break;
			case SETVAR: setvar(varkey, varval); break;
			case '+': push(pop() + pop()); break;
			case '*': push(pop() * pop()); break;
			case '-': op2 = pop(); push(pop() - op2); break;
			case '/': op2 = pop(); 
					  if(op2 != 0.0) push(pop() / op2);
					  else printf("Error: zero divisor \n"); break;
			case '%': op2 = pop(); 
					  if(op2 != 0.0) push(fmod(pop(), op2));
					  else printf("Error: zero divisor \n"); break;
			case '\n': printf("\t%.8g\n", recent = pop()); break;
			default: printf("Error: unknown command\n"); break;
		}
	}
	return 0;
}

double getvar(int c)
{
	if (status[c - 'a']) return variables[c - 'a'];
	else printf("Error: variable not set.\n");
	return 0.0;
}

void setvar(int varkey, double varval)
{
	variables[varkey - 'a'] = varval;
	++status[varkey - 'a'];
	printf("SETTING %c TO %g\n", varkey, varval);
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
	else if (strcmp(s, "ans") == 0){
		if (recent) return recent;
		else {
			printf("Error: no previous result.\n");
			return 0.0;
		}
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
	static int store = -1;

	while ((s[0] = c = ((store == -1) ? getchar() : store)) == ' ' || c == '\t')
		store = -1;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-' && c!='$') return c;
	if (c == '$'){
		if('a' <= (s[++i] = c = ((store == -1) ? getchar() : store)) && c <= 'z'){
			store = -1;
			while (isdigit(s[++i] = c = ((store == -1) ? getchar() : store)))
				store = -1;
			s[i] = '\0';
			varkey = s[1];
			s[0] = '0';
			s[1] = '0';
			varval = atof(s);
			return SETVAR;
		}
		else {
			store = c;
			return '$';
		}
	}
	if (c == '-'){
		if (isdigit(s[++i] = c = ((store == -1) ? getchar() : store))){
			store = -1;
			while (isdigit(s[++i] = c = ((store == -1) ? getchar() : store)))
				store = -1;
		}
		else {
			store = c;
			return '-';
		}
	}
	if (isalpha(c)){
		while (isalpha(s[++i] = c = ((store == -1) ? getchar() : store)))
			store = -1;
		s[i] = '\0';
		store = c;
		if (strlen(s) == 1 && 'a' <= s[0] && s[0] <= 'z') return GETVAR;
		return ALPHA;

	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = ((store == -1) ? getchar() : store)))
			store = -1;
	if (c == '.')
		while (isdigit(s[++i] = c = ((store == -1) ? getchar() : store)))
			store = -1;
	s[i] = '\0';
	store = c;
	return NUMBER;
}