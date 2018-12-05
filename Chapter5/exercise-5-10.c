#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100

void push(double f);
double pop(void);

int main(int argc, char *argv[])
{
	double op2;

	while (--argc > 0){
		if (isdigit((*++argv)[0])) /* lazy implementation that will just take something like 23abxd as 23 and ignore the rest */
			push(atof(*argv));
		else{
			switch((*argv)[0]){
				case '+': push(pop() + pop()); break;
				case '*': push(pop() * pop()); break;
				case '-': op2 = pop(); push(pop() - op2); break;
				case '/': 
					(op2 = pop()) == 0.0 ? printf("Error: division by zero\n") : push(pop() / op2); break;
				default: printf("Error: Unrecognized operand %s\n", *argv); break;
			}
		}
	}
	printf("Result: %g\n", pop());
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
		printf("Error: stack empty.\n");
		return 0.0;
	}
}