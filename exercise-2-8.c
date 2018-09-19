#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main(){

	unsigned int x = 	0b01111001;
	unsigned int res =  0b10010111;
	printf("Expected result for rightrot(%d, 4):\t\t %d\n", x, res);
	printf("Actual result for rightrot(%d,4):\t\t %d\n", x, rightrot(x,4));
	return 0;
}

unsigned int rightrot(unsigned int x, int n){

	unsigned int mask = (1 << n) - 1;
	unsigned int y = x&mask;
	x >>= n;
	unsigned int temp = x;
	int counter = 0;
	while (x!=0){
		x>>=1;
		++counter;
	}
	y<<=(counter+1);
	y|=temp;

	return y;

}