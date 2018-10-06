#include <stdio.h>
#include <string.h>
#include <limits.h>

#define SIZE 100

void itoa(int n, char s[]);
void reverse(char s[]);

/* The original itoa() doesn't deal with the minimum value for a signed int correctly because there
isn't space for the positive version (absolute value) to be stored in an int variable. Since this
isjust a single possible case, I remedied this by just checking for said case, noting
it, adding one, and checking back after the conversion was completed, then adding one to the first
digit of the string (last digit of input int). This digit can never be 9 for the minimum value and break
since (2^n)-1 is never 9. */

//Note - for the next exercise I used the abs() function from stdlib.h as a more general technique, but I
//kept this here because it's another way to do this exercise (and I think it may be more efficient for
// this single case, though I'm not sure)

int main(){

	char s[SIZE];
	char t[SIZE];
	itoa(INT_MAX-UINT_MAX, s);
	itoa(3748234, t);
	printf("%s\n", s);
	printf("%s\n", t);
	return 0;
}

void itoa(int n, char s[]){

	int i, sign, flag;
	i = sign = flag = 0;

	if (n == INT_MAX-UINT_MAX) {
		flag=1;
		++n;
	}
	if ((sign = n) < 0) n = -n;
	do{
		s[i++] = n % 10 + '0';
		printf("CURRENT N: %d\t CURRENT S: %s\n", n, s);
	} while ((n /= 10) > 0);
	if (sign < 0) s[i++] = '-';
	s[i] = '\0';
	if (flag==1) ++s[0];
	reverse(s);
}

void reverse(char s[]){

	int c, i, j;

	for (i=0, j=strlen(s)-1; i<j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}