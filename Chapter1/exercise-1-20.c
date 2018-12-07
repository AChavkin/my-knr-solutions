#include <stdio.h>

#define TABSTOP 5

int main(void)
{
	char c;
	int i, counter;
	counter = 0;

	while ((c = getchar()) != EOF){
		if (c == '\n'){
			putchar(c);
			counter = 0;
		}
		else if (c == '\t'){
			i = counter % TABSTOP;
			while (i++ != TABSTOP){
				putchar(' ');
				counter++;
			}
		}
		else{
			putchar(c);
			counter++;
		}
	}
	return 0;
}