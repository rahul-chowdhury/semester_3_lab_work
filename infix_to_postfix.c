#include<stdio.h>
#define N 100
struct stack
{
	char data[N];
	int top;
};
struct stack s;
void create()
{
	s.top=-1;
}
void push(char c)
{
	if(s.top==N-1)
	{
		printf("stack overflow\n");
		exit(1);
	}
	s.data[++(s.top)]=c;
}
char pop()
{
	if(s.top==-1)
	{
		printf("stack underflow\n");
		exit(2);
	}
	return s.data[(s.top)--];
}
int is_operand(char c)
{
	if(!(c=='+' || c=='-' || c=='*' || c=='/' || c=='$' || c=='(' || c==')' || c=='{' || c=='}' || c=='[' || c==']'))
		return 1;
	return 0;
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
void postfix(char *infix,char *result)
{
int i=0,x=0;
char c,temp;
while(infix[i]!='\0')
{
	c=infix[i++];
	if(is_operand(c)==1)
	{
		result[x++]=c;
		continue;
	}
	else
	{
		if(c=='(' || c=='{' || c=='[')
		{
			push(c);
			continue;
		}
		if(c==')' || c=='}' || c==']')
		{
			c=pop();
			while(!(c=='(' || c=='{' || c=='['))
			{
				result[x++]=c;
				c=pop();
			}
			continue;
		}
		if(s.top==-1)
		push(c);
		else
		{
			temp=pop();
			if(preference(temp,c)==1)
			{
				result[x++]=temp;
				push(c);
				continue;
			}
			else
			{
				push(temp);
				push(c);
			}
	
		}
	}
}
while(s.top!=-1)
{
result[x++]=pop();
}
result[x]='\0';
}
int main()
{
char infix[100],result[100];
printf("enter infix expression : ");
scanf("%s",infix);
create();
postfix(infix,result);
printf("corresponding postfix expression :%s\n",result);
return 0;
}
