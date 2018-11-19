#include <stdio.h>

#define SIZE 100

char *mystrncpy(char *s, const char *t , char n);
char *mystrncat(char *s, const char *t , char n);
int mystrncmp(const char *s, const char *t , char n);

int main()
{
	char s[SIZE] = "thisand";
	char t[SIZE] = "that";
	char u[SIZE] = "foods";
	char v[SIZE] = "barrrrrs";
	char w[SIZE] = "ultimate";
	char x[SIZE] = "ultimown";
	char y[SIZE] = "ultimate";
	char z[SIZE] = "ulximate";
	printf("%s\n", mystrncat(s, t, 3));
	printf("%s\n", mystrncpy(u, v, 10));
	printf("%d\n", mystrncmp(w, x, 5));
	printf("%d\n", mystrncmp(w, x, 6));
	printf("%d\n", mystrncmp(w, y, 5));
	printf("%d\n", mystrncmp(w, z, 5));
	return 0;
}

char *mystrncat(char *s, const char *t, char n)
{
	char iter = 0;
	char *track = s;
	while(*s) s++;
	while((*s++ = *t++) && ++iter < n) ;
	s = track;
	return s;
}

int mystrncmp(const char *s, const char *t , char n)
{
	char iter = 0;
	while (iter++ < n){
		if (*s++ == *t++) continue;
		else if (*s < *t) return -1;
		else return 1;
	} 
	return 0;
}

char *mystrncpy(char *s, const char *t , char n)
{
	char iter = 0;
	while((*(s+iter)=*(t+iter)) && iter<n) iter++;
	*(s+n) = '\0';
	return s;
}