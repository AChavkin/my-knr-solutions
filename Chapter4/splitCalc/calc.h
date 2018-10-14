#define NUMBER '0'
#define ALPHA '1'
#define GETVAR '2'
#define SETVAR '3'

int getop(char s[]);
void push(double f);
double pop(void);
void peek(void);
void duplicate(void);
void swap(void);
void clear(void);
int getch(void);
void ungetch(int c);

int varkey;
double varval;