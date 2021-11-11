#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		newn->next=*Head;
		(*Head)->prev=newn;
		*Head=newn;
	}
}
void InsertLast(PPNODE Head,int no)
{
	PNODE newn=NULL;
	PNODE temp=*Head;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
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
		newn->prev=temp;
	}
}
void Display(PNODE Head)
{
	while(Head!=NULL)
	{
		printf("|%d->|",Head->data);
		Head=Head->next;
	}
	printf("|NULL||\n");	
}
int  Count(PNODE Head)
{
	int iCnt=0;
	while(Head!=NULL)
	{
		iCnt++;
		Head=Head->next;
	}
	return iCnt;
}

int main()
{
	PNODE first=NULL;
	int iret=0;
	int choise=1,no=0;
	while(choise!=0)
	{	printf("\n__________________________\n");
		printf("1 : InSert  the Data in First Position\n");
		printf("2 : InSert  the Data in Last Position\n");
		printf("3 : InSert  the Data in any  Position\n");
		printf("4 : Delete  the Data from the  First Position\n");
		printf("5 : Delete  the Data from Last Position\n");
		printf("6 : Delete  the Data from  Any  Position\n");
		printf("7 : Display the Data \n");
		printf("8 : Count  the Data \n");
		printf("0 : Terminate The Code \n");
		printf("\n________________________________\n");
		printf("Enter the number that opration we have to perform\n");
		
		scanf("%d",&choise);
		switch(choise)
		{
			case 1: printf("Enter  the data\n");
					scanf("%d",&no);
					InsertFirst(&first,no);
					break;
			case 2: printf("Enter the data\n");
					scanf("%d",&no);
					InsertLast(&first,no);
					break;
			case 3: printf("Enter the data\n");
					scanf("%d",&no);
					printf("Enter the Position\n");
					scanf("%d",&iret);
					//InsertAtPos(&first,no,iret);
					break;
			case 4:
					//DeleteFirst(&first);
					break;
			case 5:
					//DeleteLast(&first);
					break;
			case 6: printf("Enter the Position\n");
					scanf("%d",&iret);
					//DeleteAtPos(&first,iret);
					break;
			case 7:	printf("The data is\n");
					Display(first);
					break;
			case 8:
					iret=Count(first);
					printf("the total number of data count is %d",iret);
					break;
			case 0:	printf("\n******Thank you for using aour application******\n");
					break;
			default: printf("Wrong input");
					 break;
		}
	}

	return 0;
}