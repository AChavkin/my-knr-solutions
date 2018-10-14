#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calc.h"

#define NUMVARS 26
#define MAXOP 100

double mathfunc(char s[]);
double getvar(int c);
void setvar(int varkey, double varval);

extern int varkey;
extern double varval;

double op2;
double variables[NUMVARS];
int status[NUMVARS];
double recent = 0.0;

int main()
{
	int type;
	//double op2;
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

	//double op2;

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