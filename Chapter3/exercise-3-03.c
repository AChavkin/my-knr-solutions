#include <stdio.h>

#define SIZE 1000

void expand(char s[], char t[]);

int main(){

	char s1[]="-a]a-z;!B-C-Dq-x!z-";
	char s2[SIZE];

	expand(s1,s2);

	printf("%s\n", s2);

	return 0;
}

void expand(char s1[], char s2[]){

	int i, j;
	char c;

	j=0;

	for (i=0; s1[i]!='\0'; i++){
		if (s1[i]=='-' && i!=0 && s1[i+1]!='\0' && \
			((('A'<= s1[i-1] && s1[i-1] <= 'Z') && ('A'<= s1[i+1] && s1[i+1] <= 'Z')) || \
			(('a'<= s1[i-1] && s1[i-1] <= 'z') && ('a'<= s1[i+1] && s1[i+1] <= 'z')) || \
			(('0'<= s1[i-1] && s1[i-1] <= '9') && ('0'<= s1[i+1] && s1[i+1] <= '9')))){
			for (c=(s1[i-1]+1); c<s1[i+1]; c++){
				s2[j++]=c;
			}
		}
		else s2[j++]=s1[i];
	}
	s2[j]='\0';
}