#include <stdio.h>

int lower(int c);

int main(){

	int c = 'B';
	int d = 'd';
	printf("%c\n%c\n", lower(c), lower(d));

	return 0;
}

int lower(int c){

	c = (c >= 'A' && c<= 'Z') ? (c + 'a' - 'A') : c;
	return c;

}