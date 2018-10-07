#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
	char s[] = "123.45e-11";
	char t[] = "123.45e20";
	printf("%g\n", atof(s));
	printf("%g\n", atof(t));

	return 0;
}

double atof(char s[])
{
	double val, power, exp;
	int i, sign, expnegative;
	exp = 0;

	/* Skip whitespace */
	for (i=0; isspace(s[i]); i++)
		;
	/* Get sign */
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') i++;
	/* Convert everything before the decimal to a double */
	for (val = 0.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') i++;
	/* Convert everything between the decimal and either an exponent
	or the end to a double and start tracking the power */
	for (power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	/* Check for scientific notation and if so, the exponent's sign */
	if (s[i] == 'e' || s[i] == 'E'){
		expnegative = (s[++i] == '-') ? 1 : 0;
		if (expnegative) i++;
	}
	/* Convert the exponent from string to double */
	for (exp = 0.0; isdigit(s[i]); i++) exp = 10.0 * exp + (s[i] - '0');
	/* Modify the power according to the exponent after the scientific notation */
	for (i = 0; i < exp; i++) {
		if (expnegative) power*=10.0;
		else power /= 10.0;
	}
	return sign * val / power;
}