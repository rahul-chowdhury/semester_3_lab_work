#include<stdio.h>
struct list
{
struct list *node;
int data;
};
struct list *start;
void insert(int x)
{
struct list *newnode=(struct list *)malloc(sizeof(struct list));
newnode->data=x;
newnode->node=NULL;
struct list *l=start;
if(start==NULL)
{
start=newnode;
return;
}
while(l->node!=NULL)
l=l->node;
l->node=newnode;
}
void print()
{
struct list *l=start;
l=l->node;
if(l==NULL)
{
printf("empty list\n\n");
return;
}
printf("the list is : ");

while(l!=NULL)
{
printf("%d\t",l->data);
l=l->node;
}
printf("\n");
}
void delete(int x)
{
int i=1;
if(start==NULL)
{
printf("list is empty.no element available for deletion\n\n\n");
return;
}
struct list *l=start;
l=l->node;
while(l->node!=NULL && (l->node)->data!=x  )
{l=l->node;
i++;
}
if(l->node==NULL)
{
printf("element is not present in the list.\n\n\n");
return;
}
l->node=(l->node)->node;
printf("deleted element was present at position %d\n\n",i);

}
int main()
{
start=(struct list *)malloc(sizeof(struct list));
int menu=1;
char choice,dummy;
while(menu==1)
{
scanf("%c",&dummy);
printf("ENTER YOR CHOICE:\n1->insert an element\n2->delete an element\n3->show the current list\n4->exit menu\n");

scanf("%c",&choice);
switch(choice)
{
case '1':
{
int x;
printf("enter the element to be inserted: ");
scanf("%d",&x);

insert(x);
break;
}
case '2':
{
int x;
printf("enter the element you want to delete: ");
scanf("%d",&x);
delete(x);
break;
}
case '3':
{
print();
break;
}
case '4':
{
menu=0;
printf("************************THANK YOU!!****************************\n\n");
break;
}
default:
{
printf("wrong choice.try again.\n");
break;
}
}
}
}







































