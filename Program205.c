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

void InsertFirst(PPNODE Head ,int no)
{
	PNODE newn=NULL;
	//step 1  Allocate the Memory
	newn=(PNODE)malloc(sizeof(NODE));
	//step 2 Initialize the node
	newn->data=no;
	newn->next=NULL;

	//step 3 insert the node	
	if(*Head==NULL)
	{
		*Head=newn;
	}
	else 
	{
		newn->next=*Head;
		*Head=newn;
	}
}
void InsertLast(PPNODE Head ,int no)
{
	PNODE newn=NULL;
	PNODE temp=*Head;
	//step 1  Allocate the Memory
	newn=(PNODE)malloc(sizeof(NODE));
	//step 2 Initialize the node
	newn->data=no;
	newn->next=NULL;
	
	//step 3 insert the node	
	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
}
void Display(PNODE Head)
{
	while(Head!=NULL)
	{
		printf("%d\t",Head->data);
		Head=Head->next;	
	}
}
int Count(PNODE Head)
{
	int count=0; 
	while(Head!=NULL)
	{
		count++;
		Head=Head->next;
	}
	return count;
}
	
void DeleteFirst(PPNODE Head)
{
	PNODE temp=*Head;
	if(*Head!=NULL)//if LL contains atleast one node
	{
		*Head= (*Head)->next;
		free(temp);
	}
}	
void DeleteLast(PPNODE Head)
{
	PNODE temp=*Head;
	if(*Head==NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)//if LL contains atleast one node
	{
		free(*Head);
		*Head=NULL;
	}
	else 
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}

int main()
{
	int iret=0;
	PNODE first=NULL;
	InsertFirst(&first,51); //InsertFirst(50,51)
	InsertFirst(&first,21); //InsertFirst(50,21)
	InsertFirst(&first,11); //InsertFirst(50,11)
	InsertFirst(&first,101); //InsertFirst(50,111)
	InsertLast(&first,111); //InsertFirst(50,11)
	
	Display(first);
	
	iret=Count(first);
	printf("\nNumber of elementd is :%d\n",iret);
	
	DeleteFirst(&first);
	DeleteLast(&first);
	Display(first);
	
	iret=Count(first);
	printf("\nAfter Delete first Number of elementd is :%d\n",iret);
	
	return 0;
}
