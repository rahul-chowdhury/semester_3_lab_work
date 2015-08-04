#include<stdio.h>
#include<math.h>
#define N 100
struct tree
{
	struct tree *left,*right;
	char data;
};
struct treestack
{
	struct tree *data[N];
	int top;
};
struct treestack s;
int isoperand(char c)
{
	if(!(c=='+' || c=='-' || c=='*' || c=='/' || c=='$'|| c=='(' || c==')' || c=='{' || c=='}' || c=='[' || c==']'))
		return 1;
	return 0;
}
struct stack
{
	int data[N];
	int top;
};

void create(struct stack *s1)
{
	s1->top=-1;
}
void push(struct stack *s1,int c)
{
	if(s1->top==N-1)
	{
		printf("stack overflow\n");
		exit(1);
	}
	s1->data[++(s1->top)]=c;
}
int pop(struct stack *s1)
{
	if(s1->top==-1)
	{
		printf("stack underflow\n");
		exit(2);
	}
	return s1->data[(s1->top)--];
}
void treecreate()
{
	s.top=-1;
}
void treepush(struct tree *node)
{
	if(s.top==N-1)
	{
		printf("stack overflow\n");
		exit(1);
	}
	s.data[++(s.top)]=node;
}
struct tree * treepop()
{
	if(s.top==-1)
	{
		printf("stack underflow\n");
		exit(2);
	}
	return s.data[(s.top)--];
}
struct tree* convert(char *c)
{
	treecreate();
	char x;
	int i=0;
	while(c[i]!='\0')
	{
		x=c[i++];
		if(isoperand(x)==1)
		{
			struct tree *node=(struct tree*)malloc(sizeof(struct tree));
			node->data=x;
			treepush(node);
		}
		else
		{
			struct tree *node=(struct tree*)malloc(sizeof(struct tree));
			node->right=treepop();
			node->left=treepop();
			node->data=x;
			treepush(node);
		}
	}		
	struct tree *node=(struct tree*)malloc(sizeof(struct tree));
	node=treepop();
	return node;
}
void evaluate(struct stack *s2,struct tree *node)
{
	char x;
		if(node!=NULL)
	{
		evaluate(s2,node->left);	
		evaluate(s2,node->right);	
		x=node->data;
		if(isoperand(x)==1)
			push(s2,x-'0');
		else
		{
			int op1=pop(s2);
			int op2=pop(s2);
			switch(x)
			{
				case '+':{push(s2,op2+op1);break;}
				case '-':{push(s2,op2-op1);break;}
				case '*':{push(s2,op2*op1);break;}
				case '/':{push(s2,(int)(op2/op1));break;}
				case '$':{push(s2,(int)(pow(op2,op1)));break;}
				default:{printf("wrong symbol\n");exit(3);}
			}
		}
	}
}
int preference(char a,char b)
{
	if(a=='$')
	return 1;
	if(a=='*' || a=='/')
	{
	if(b=='$')
	return 0;
	else
	return 1;
	}
	if(a=='+' || a=='-')
	{
	if(b=='+' || b=='-')
	return 1;
return 0;
}
}
void postfix(struct stack *s1,char *infix,char *result)
{
int i=0,x=0;
char c,temp;
while(infix[i]!='\0')
{
	c=infix[i++];
	if(isoperand(c)==1)
	{
		result[x++]=c;
		continue;
	}
	else
	{
		if(c=='(' || c=='{' || c=='[')
		{
			push(s1,c);
			continue;
		}
		if(c==')' || c=='}' || c==']')
		{
			c=pop(s1);
			while(!(c=='(' || c=='{' || c=='['))
			{
				result[x++]=c;
				c=pop(s1);
			}
			continue;
		}
		if(s1->top==-1)
		push(s1,c);
		else
		{
			temp=pop(s1);
			if(preference(temp,c)==1)
			{
				result[x++]=temp;
				push(s1,c);
				continue;
			}
			else
			{
				push(s1,temp);
				push(s1,c);
			}
	
		}
	}
}
while(s1->top!=-1)
{
result[x++]=pop(s1);
}
result[x]='\0';
}//end of postfix
int limit=0,t;
//print functions
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
printf("THE EXPRESSION TREE IS :\n");
for(j=1;j<(int)(pow(2,height));j++)
               { printf(" ");}

printf("%c\n",node->data);
for(i=1;i<=height;i++)
{
t=(int)(pow(2,height-i));
                for(j=1;j<(int)(pow(2,height-i));j++)
               { printf(" ");}

limit=i;
print_tree(node,0);
printf("\n\n");
}
}
//end of print functions
int main()
{
int i=0;
struct stack s1,s2;
char infix[100],result[100];
printf("enter infix expression : ");
scanf("%s",infix);
create(&s1);
postfix(&s1,infix,result);
int n=strlen(result);
for(i=1;;i++)
{
if(n>=(int)pow(2,i-1) && n<=((int)pow(2,i)-1))
break;
}
printf("postfix expression is : %s\n",result);
create(&s2);
struct tree *node=(struct tree*)malloc(sizeof(struct tree));
node=convert(result);
print_call(node,i);
evaluate(&s2,node);
printf("value of the expression : %d\n",pop(&s2));
return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	



