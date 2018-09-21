#include <stdio.h>

int setbits(unsigned int x, int n, int p, unsigned int y);

int main(){

	unsigned int x= 	0b110100111;
	unsigned int y=		0b100110001;
	unsigned int result=	0b110000111;
	printf("Expected result for setbits(x,4,2,y): %d\n",result);
	printf("Actual result for setbits(x,4,2,y):   %d\n",setbits(x,4,2,y));
	return 0;

}

int setbits(unsigned int x, int n, int p, unsigned int y){

	unsigned int mask = ((1<<n)-1)<<p;
	x &= ~mask;
	y = (y<<p) & mask;
	x |= y;
	return x;
	
}
