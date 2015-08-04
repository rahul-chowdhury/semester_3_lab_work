#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include<string.h>
struct queue	//declaring queue structure
{
	char name[100];
	struct queue *node;
};
struct queue *list=NULL;
void insert(char *c)	//function to insert new node into the queue
{
	struct queue *q=(struct queue *)malloc(sizeof(struct queue));	//allocating space for the new node
	if(list==NULL)
	{
		list=q;
		strcpy(q->name,c);
		q->node=q;
	}
	else
	{
		strcpy(q->name,c);
		q->node=list->node;
		list->node=q;
		list=q;
	}
}	//end of function insert()

void delete()	//function to delete a node from the queue list
{
	if(list==NULL)
	{
		printf("queue underflow\n");
		exit(1);
	}
	else if(list->node==list)
	{
		list=NULL;
	}
	else
	{
		list->node=(list->node)->node;
	}
}	//end of function delete()
int main()
{
	srand(time(NULL));	//seeding the random function
	int n,i,r;
	char c[100];
	printf("enter the number of soldiers: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("enter name of soldier %d: ",i);
		scanf("%s",c);
		insert(c);	//inserting soldier names into the queue
	}
	printf("enter the name of the starting soldier: ");
	scanf("%s",c);
	while(1)
	{
		if(strcmp((list->node)->name,c)==0)
		break;
		list=list->node;	//making list equal to node containing name of starting soldier
	}
	while(list!=list->node)
	{
		r=rand()%n;	//picking a random number
		for(i=1;i<=r;i++)
			list=list->node;
		delete();	//removing soldier name from list
		n--;
	}
	printf("the selected soldier is %s\n",list->name);	//printing the result
	return 0;
}	//end of main function


















