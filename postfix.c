#include<stdio.h>
#define N 100
struct stack
{
int top;
char items[N];
};
struct stack p;
int isoperand(char c)
{
if(c!='+' && c!='-' && c!='*' && c!='/' && c!='(' && c!=')' && c!='{' && c!='}' && c!='[' && c!=']' && c!='$')
return 1;
else
return 0;
}
void pop(stack *s,char *c,int *under)
{
if(empty(&s)==1)
{
	under=1;
return;
}
under =0;
&c=(&s).items[(&s).top--];
}
int empty(stack *s)
{
if((&s).top==-1)
return 1;
return 0;
}
void push(stack *s,char c)
{
if((&s).top==N-1)
{
printf("stack overflow\n");
exit(1);
}
else
(&s).items[++((&s).top)]=c;
}
int prcd(char a,char b)
{
if(a=='$')
return 1;
if(a=='*' || a=='/')
{
if(b=='$')
return 0;
else return 1;
}
if(a=='+' || a=='-')
{
if(b=='+' || b=='-')
return 1;
else return 0;
}
}
void postfix(char *infix,char *result)
{
int i=0,under,outpos=0;
char topsymb='+',symb;
p.top=-1;
while(infix[i]!='\0')
{
symb=infix[i++];
if(isoperand(symb)==1)
result[outpos++]=symb;
else
{
pop(&p,&topsymb,&under);
while(under==0 && prcd(topsymb,symb))
{
result[outpos++]=topsymb;
pop(&p,&topsymb,&under);
}
if(under==0)
push(&p,topsymb);
if(under==1 || (symb!=')'))
push(&p,symb);
else
pop(&p,&topsymb,&under);
}
}
while(empty(&p)!=1)
{
pop(&p,&topsymb,&under);
result[outpos++]=topsymb;
}
result[outpos]='\0';
}
int main()
{
char infix[N],result[N];
int pos=0;
scanf("%s",infix);
printf("the original expression : %s\n",infix);
postfix(infix,result);
printf("postfix expression : %s\n",result);
return 0;
}

















                                                                                                                                                                                                                                         




                                                                                                                                                                                                                                         
