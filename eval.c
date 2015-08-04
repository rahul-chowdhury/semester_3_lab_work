#include<stdio.h>
#include<math.h>
#include <string.h>
#define N 100
struct stack
{
int data[N];
int top;
};
struct stack s;
void create()
{
s.top=-1;
}
void push(int c)
{
if(s.top==N-1)
{
printf("stack overflow\n");
exit(1);
}
s.data[++(s.top)]=c;

}
int pop()
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
if(!(c=='+' || c=='-' || c=='*' || c=='/' || c=='$'))
return 1;
return 0;
}
int evaluate(char *str)
{
int i=0,op1,op2,x;
char *c=strtok(str," ,.");
while(c!=NULL)
{

if(c[0]<=57 && c[0]>=48)
x=atoi(c);
else 
x=c[0];
c=strtok(NULL," ,.");
if(is_operand(x)==1)
{
push(x);
continue;
}
else
{
op1=pop();
op2=pop();
switch(x)
{
case '+':{push(op2+op1);break;}
case '-':{push(op2-op1);break;}
case '*':{push(op2*op1);break;}
case '/':{push((int)(op2/op1));break;}
case '$':{push((int)(pow(op2,op1)));break;}
default:{printf("wrong symbol\n");exit(3);}
}
}
}
return pop();
}
int main()
{
char str[100];
printf("enter postfix expression to be evaluated: ");
gets(str);
create();
printf("the value of the expression :%d\n",evaluate(str));
return 0;
}






























 
