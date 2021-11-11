#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data ;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int main()
{
	NODE obj;
	obj.data=11;
	obj.next=NULL;
	
	PNODE p=NULL;
	p=&obj;
	
	PPNODE q =NULL;
	q=&p;
	
	
	
	return 0;
}
