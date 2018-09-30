#include <stdio.h>

#define SIZE 50

void escape(char s[], char t[]);
void jail(char s[], char t[]);

int main(){

	char s[SIZE];
	char t[] = "a	b 	c1 \" \nd";

	escape(s, t);

	char a[SIZE];
	char b[] = "\\t \\n \\a \\? \\\'\\n\\\"\\?\\t\\a\\\'\\n";

	jail(a,b);

	printf("%s\n", s);
	printf("%s\n", a);

	return 0;
}

void escape(char s[], char t[]){

	int i,j;
	j=0;

	for(i=0; t[i]!='\0'; ++i){

		switch(t[i]){

			case '\t': s[j]='\\'; s[++j]='t'; break;
			case '\n': s[j]='\\'; s[++j]='n'; break;
			case '\a': s[j]='\\'; s[++j]='a'; break;
			case '\b': s[j]='\\'; s[++j]='b'; break;
			case '\f': s[j]='\\'; s[++j]='f'; break;
			case '\r': s[j]='\\'; s[++j]='r'; break;
			case '\v': s[j]='\\'; s[++j]='v'; break;
			case '\?': s[j]='\\'; s[++j]='\?'; break;
			case '\'': s[j]='\\'; s[++j]='\''; break;
			case '\"': s[j]='\\'; s[++j]='\"'; break;
			default: s[j]=t[i]; break;
		}
		++j;
	}
	s[j]='\0';
}

void jail(char s[], char t[]){

	int i,j;
	j=0;

	for(i=0; t[i]!='\0'; ++i){

		if (t[i]=='\\'){

			switch(t[++i]){

			case 't': s[j]='\t'; break;
			case 'n': s[j]='\n'; break;
			case 'a': s[j]='\a'; break;
			case 'b': s[j]='\b'; break;
			case 'f': s[j]='\f'; break;
			case 'r': s[j]='\r'; break;
			case 'v': s[j]='\v'; break;
			case '\?': s[j]='\?'; break;
			case '\'': s[j]='\''; break;
			case '\"': s[j]='\"'; break;
			case '\\': s[j]='\\'; break;
			default: break;

			}
		}
		else s[j]=t[i];
		++j;
	}
	s[j]='\0';
}