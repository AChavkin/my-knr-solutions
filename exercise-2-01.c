#include <stdio.h>
#include <limits.h>

int main(){

	printf("Signed char max: %d\nUnisgned char max: %d\nSigned char min: %d\n"
		"Signed int max: %d\nUnsigned int max: %u\nSigned int min: %d\n"
		"Signed long max: %li\nUnsigned long max: %lu\nSigned long min: %li\n"
		"Signed short max: %d\nUnsigned short max: %d\nSigned short max: %d\n", \
		CHAR_MAX, UCHAR_MAX, CHAR_MAX-UCHAR_MAX, INT_MAX, UINT_MAX, INT_MAX-UINT_MAX, \
		LONG_MAX, ULONG_MAX, LONG_MAX-ULONG_MAX, SHRT_MAX, USHRT_MAX, SHRT_MAX-USHRT_MAX);
	return 0;
}