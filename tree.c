#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node
{
	char data;
	struct node* left;
	struct node* right;
};
int x;
typedef struct node node;
char* substring(char* str,int p1,int p2)
{
	char* st;
	st=(char*)malloc(50*sizeof(char));
	int i,j=0;
	for(i=p1;i<=p2;i++)
		st[j++]=str[i];
	st[j]='\0';
	return st;
}
node* createTree(node* ptr)
{
	ptr=NULL;
	return ptr;
}
void makeTree(node** ptr,char* pre,char* in)
{
	if(strlen(in)==0)
		return;
	char* in1;
	char* in2;
	in1=(char*)malloc(50*sizeof(char));
	in2=(char*)malloc(50*sizeof(char));
	char temp1[50];
	char temp2[50];
	char x=pre[0];
	int i,j,k=0;
	for(i=0;i<strlen(in);i++)
	{
		if(x==in[i])
			break;
	}
	(*ptr)=(node*)malloc(sizeof(node));
	(*ptr)->data=x;
	in1=substring(in,0,(i-1));
	in2=substring(in,(i+1),(strlen(in)-1));
	for(i=0;i<strlen(pre);i++)
	{
		for(j=0;j<strlen(in1);j++)
		{
			if(pre[i]==in1[j])
				temp1[k++]=pre[i];
		}
	}
	temp1[k]='\0';
	k=0;
	for(i=0;i<strlen(pre);i++)
	{
		for(j=0;j<strlen(in2);j++)
		{
			if(pre[i]==in2[j])
				temp2[k++]=pre[i];
		}
	}
	temp2[k]='\0';
	makeTree(&((*ptr)->left),temp1,in1);
	makeTree(&((*ptr)->right),temp2,in2);
}
void printPost(node* ptr)
{
	if(ptr==NULL)
		return;
	printPost(ptr->left);
	printPost(ptr->right);
	printf("%c",ptr->data);
}
int findHeight(node* ptr)
{
	if(ptr==NULL)
		return 0;
	else
	{
		int left=findHeight(ptr->left);
		int right=findHeight(ptr->right);
		if(left>right)
			return(left+1);
		else
			return(right+1);
	}
}
void printLevel(node* ptr,int level)
{
int i;
	if(ptr==NULL)
	{
				return;
	}
	if(level==0)
			{
printf("%c",ptr->data);
for(i=0;i<x;i++)
printf(" ");
}
	else if(level>0)
	{
		printLevel(ptr->left,level-1);
					printLevel(ptr->right,level-1);


}
		
}
void treePrint(node* ptr)
{
	int h=findHeight(ptr);
	int i,j;
	for(i=0;i<h;i++)
	{x=(int)(pow(2,h-i));

		for(j=1;j<(int)(pow(2,h-1-i));j++)
		printf(" ");
		printLevel(ptr,i);
		printf("\n\n");
	}
}
int main()
{
	node* ptr;
	ptr=createTree(ptr);
	char pre[100];
	char in[100];
	system("CLS");
	printf("ENTER PREORDER:");
	gets(pre);
	printf("ENTER INORDER:");
	gets(in);
	makeTree(&ptr,pre,in);
	printf("\n\nThe Tree Is:\n\n");
	treePrint(ptr);
	printf("\nPOSTORDER NOTATION: ");
	printPost(ptr);
	printf("\n\n");
	return 0;
}
