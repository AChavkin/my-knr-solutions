#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

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