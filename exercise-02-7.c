#include <stdio.h>

int invert(unsigned int x, int n,int p);

int main(){

	unsigned int something=0b110100111;
	unsigned int result=0b110011011;
	printf("Expected result for invert(110100111,4,2): %d\n", result);
	printf("%d\n",invert(something,4,2));
	return 0;
}

int invert(unsigned int x, int n, int p){

	unsigned int mask;
	mask=((1 << n) - 1) << p;
	return x^mask;

}
