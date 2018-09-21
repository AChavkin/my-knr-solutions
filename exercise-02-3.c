#include <stdio.h>
#include <math.h>

#define HEXSIZE 6

int check_hex(char hex[]);
int htoi(char hex[], int len);

int hexlen;

int main(){

	char example_hex[HEXSIZE];

	example_hex[0]='b';
	example_hex[1]='b';
	example_hex[2]='b';
	example_hex[3]='d';
	example_hex[4]='9';
	example_hex[5]='\0';

	if (check_hex(example_hex)) printf("%d\n", htoi(example_hex, hexlen));
	else printf("Not a valid hex value.\n");

	return 0;

}

int check_hex(char hex[]){

	int i, start, flag;

	flag=1;

	if (hex[0]=='0' && (hex[1]=='x'||hex[1]=='X')) {
		start=2;
		hexlen=1;
	}
	else {
		start=0; 
		hexlen=-1;
	}

	for(i=start;hex[i]!='\0';++i){

		if ((('0'<=hex[i]&&hex[i]<='9')) || ('a'<=hex[i]&&hex[i]<='f') || ('A'<=hex[i]&&hex[i]<='F')) ;
		else flag=0;
		++hexlen;
	}

	return flag;
}

int htoi(char hex[], int len){

	int i,ctr,curval,total;
	ctr=total=0;

	for (i=len; i>=0 && hex[i]!='x'; --i) {

		if('0'<=hex[i]&&hex[i]<='9') curval = (hex[i]-'0');
		else if('a'<=hex[i]&&hex[i]<='f') curval = 10 + (hex[i]-'a');
		else curval = 10 + (hex[i]-'A');

		total += (curval * pow(16, ctr));
		++ctr;
	}
	return total;	
}