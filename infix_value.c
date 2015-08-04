#include<stdio.h>
#include<math.h>
#define N 100
struct stack
{
int data[N];
int top;
};
void create(struct stack *s)
{
s->top=-1;
}
void push(struct stack *s,int c)
{
if(s->top==N-1)
{
printf("stack overflow\n");
exit(1);
}
s->data[++(s->top)]=c;

}
int pop(struct stack *s)
{
if(s->top==-1)
{
printf("stack underflow\n");
exit(2);
}
return s->data[(s->top)--];
}
int is_operand(char c)
{
if(!(c=='+' || c=='-' || c=='*' || c=='/' || c=='$'))
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
int value(char *s)
{
struct stack operand,operator;
create(&operand);
create(&operator);
int i=0,j,op1,op2;
char c,temp;
printf("operand stack\toperator stack\n");
while(s[i]!='\0')
{
for(j=0;j<=operand.top;j++)
printf("%d ",operand.data[j]);
printf("\t\t");
for(j=0;j<=operator.top;j++)
printf("%d ",operator.data[j]);
printf("\n");
c=s[i++];
if(is_operand(c)==1)
{
push(&operand,c-'0');
continue;
}
else
{
if(operator.top==-1)
{
push(&operator,c);
continue;
}
temp=pop(&operator);
if(preference(temp,c)==1)
{
op1=pop(&operand);
op2=pop(&operand);
push(&operator,c);
switch(temp)
{
case '+':{push(&operand,op2+op1);break;}
case '-':{push(&operand,op2-op1);break;}
case '*':{push(&operand,op2*op1);break;}
case '/':{push(&operand,(int)(op2/op1));break;}
case '$':{push(&operand,(int)(pow(op2,op1)));break;}
default:{printf("wrong symbol\n");exit(3);}
}
continue;
}
else
{
push(&operator,temp);
push(&operator,c);
}
}
}
while(operator.top!=-1)
{
op1=pop(&operand);
op2=pop(&operand);
switch(pop(&operator))
{
case '+':{push(&operand,op2+op1);break;}
case '-':{push(&operand,op2-op1);break;}
case '*':{push(&operand,op2*op1);break;}
case '/':{push(&operand,(int)(op2/op1));break;}
case '$':{push(&operand,(int)(pow(op2,op1)));break;}
default:{printf("wrong symbol\n");exit(3);}
}
}
return pop(&operand);
}
int main()
{
char s[100];
printf("enter infix expression to be evaluated: ");
scanf("%s",s);
printf("the value of the expression =%d\n",value(s));
return 0;
}


















