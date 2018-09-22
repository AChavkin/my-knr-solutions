#include <stdio.h>

int main(){

	int i, c, lim;
	char s[]="PLACEHOLDER";

	/* change to sizeof(s) to avoid compilation issues, just rewriting */
	for (i=0; i<sizeof(s); ++i){
		if ((c=getchar())!='\n')
			if (c!=EOF) s[i]=c;
	}

	return 0;
}
