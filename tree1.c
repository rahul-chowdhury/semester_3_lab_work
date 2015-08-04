#include<stdio.h>
#include<string.h>
#include<math.h>
struct tree
{
struct tree *left,*right;
char data;
};
int limit=0;
char preorder[100];
int x=0,t;
struct tree *root;
void edit(char left[],char right[],char s[])
{
left[0]='\0';
int r=0,i;
right[0]='\0';
for(i=0;s[i]!='\0';i++)
{
if(s[i]==preorder[x])
break;
left[i]=s[i];
}
left[i]='\0';
for(i=i+1;s[i]!='\0';i++)
right[r++]=s[i];
right[r]='\0';
}

void create(struct tree *node,char s[])
{
if(node==NULL)
return;
char left[strlen(s)],right[strlen(s)];
edit(left,right,s);
node->data=preorder[x++];
if(left[0]=='\0')
{
node->left=NULL;
}
else
{
node->left=(struct tree *)malloc(sizeof(struct tree));
create(node->left,left);
}
if(right[0]=='\0')
{
node->right=NULL;
}
else
{
node->right=(struct tree *)malloc(sizeof(struct tree));
create(node->right,right);
}
}
void postorder(struct tree *node)
{
if(node!=NULL)
{
postorder(node->left);
postorder(node->right);
printf("%c",node->data);
}
return;
}
void print_tree(struct tree *node,int k)
{int i;
if(node==NULL)
return; 
if(k>limit)
return;
if(k==limit)
{
printf("%c ",node->data);
for(i=0;i<t;i++)
printf(" ");

return;
}
print_tree(node->left,k+1);
print_tree(node->right,k+1);
}
void print_call(struct tree *node,int height)
{
int i,j;
printf("THE TREE IS :\n");
                for(j=1;j<(int)(pow(2,height));j++)
               { printf(" ");}
printf("%c\n\n",node->data);
for(i=1;i<=height+1;i++)
{
t=(int)(pow(2,height-i));
                for(j=1;j<(int)(pow(2,height-i));j++)
               { printf(" ");}
limit=i;
print_tree(node,0);
printf("\n\n");
}
}

int main()
{
int i=0;
printf("enter the preorder string: ");
scanf("%s",preorder);
int n=strlen(preorder);
for(i=1;;i++)
{
if(n>=(int)pow(2,i-1) && n<=((int)pow(2,i)-1))
break;
}
char inorder[strlen(preorder)];
printf("enter the inorder string: ");
scanf("%s",inorder);
printf("the inorder string: %s\n",inorder);
printf("the preorder string: %s\n",preorder);
root=(struct tree *)malloc(sizeof(struct tree));
create(root,inorder);
print_call(root,i);
printf("\nthe postorder string is : ");
postorder(root);
printf("\n");
return 0;
}









