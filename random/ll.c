#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node *next;
};

struct Node *buildList (int len);

int main()
{
	buildList(10);
	return 0;
}


struct Node *buildList(int len)
{	
	int i = 4;
	struct Node head;
	struct Node *curr;
	head.next = NULL;
	curr = &head;
	for (int n = 0; n < len; n++,i+=2){
		curr->next = malloc(sizeof *(curr->next));
		curr = curr->next;
		curr->val = i;
		curr->next = NULL;
		printf("%d\n", curr->val);
	}
	return head.next;
}