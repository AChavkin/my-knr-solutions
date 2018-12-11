#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB 8

int main(int argc, char *argv[])
{
	char c;
	int i, counter, tabstop, stop;
	counter = 0;
	stop = argc - 1;

	while ((c = getchar()) != EOF){
		if (c == '\n'){
			putchar(c);
			counter = 0;
			stop = argc-1; /* start at *(argv+1) again for each new line*/
		}
		else if (c == '\t'){
			(argc == 1) ? tabstop = DEFAULT_TAB : (tabstop = atoi(*(argv+(argc-stop))));
			i = counter % tabstop;
			while (i++ != tabstop){
				putchar(' ');
				counter++;
			}
			--stop;
			if (stop == 0) stop = argc - 1; /* if there are more tabs in the same line than tabstops,
											go back to *(argv+1) and start again */
		}
		else{
			putchar(c);
			counter++;
		}
	}
	return 0;
}