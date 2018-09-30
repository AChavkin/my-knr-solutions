#include <stdio.h>

#define size 20

int binsearch(int x, int v[], int n);

int main(){

	int v[size];

	for (int i = 0; i<size; ++i){
		v[i]=i+5;
	}

	printf("\nANSWER: %d\n",binsearch(v[0]+2,v,size-1));

	return 0;
}

int binsearch(int x, int v[], int n){

	int low,mid,high;

	low = 0;
	high = n-1;

	while(low < high){
		mid = (low+high) / 2;
		if (x <= v[mid]) high = mid;
		else low = mid+1;
		printf("LOW: %d\tMID: %d\tHIGH: %d\n", low, mid, high); 

	}
	if (v[low] == x) return low;
	return -1;
}