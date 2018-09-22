#include <stdio.h>

#define FAHR 189

float convert_temp(int fahr);

int main(){

	printf("%dF = %fC\n", FAHR, convert_temp(FAHR));
	return 0;
}

float convert_temp(int fahr){

	return (fahr-32)*(5.0/9.0);
}