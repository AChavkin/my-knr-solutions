#include <stdio.h>

/* In a two's complement number system, x & (x-1) will always flip the rightmost 1-bit 
because the subtracted one will carry through each zero from the right until it "finds" a 1 bit,
where it will flip and stop carrying. Bitwise AND with 1 will keep the all bits the same,
where bitwise AND with 0 will make all bits 0 -- but this will only change 1 bit, the rightmost
position one. all further positioned bits will just be ANDed with themselves, keeping them 
the same.*/ 

int bitcount(int x);

int main(){

	int x = 0b11100011111001;
	int y = 0b00110001110111;
	printf("%d\n%d\n",bitcount(x), bitcount(y));
	return 0;

}

int bitcount(int x){

	int count = 0;
	while(x){
		x &= (x-1);
		++count;
	}
	return count;
}