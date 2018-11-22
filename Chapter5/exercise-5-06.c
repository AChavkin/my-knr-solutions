#include <stdio.h>

#define SIZE 20

int binsearch(int x, int *v, int n);

int main(){

	int v[SIZE];

	for (int i = 0; i<SIZE; ++i){
		v[i]=i+5;
	}

	printf("\nANSWER: %d\n",binsearch(v[0]+2,v,SIZE-1));

	return 0;
}

int binsearch(int x, int *v, int n){

	int low,mid,high;

	low = 0;
	high = n-1;

	while(low < high){
		mid = (low+high) / 2;
		if (x <= *(v+mid)) high = mid;
		else low = mid+1;
		printf("LOW: %d\tMID: %d\tHIGH: %d\n", low, mid, high); 

	}
	if (*(v+low) == x) return low;
	return -1;
}