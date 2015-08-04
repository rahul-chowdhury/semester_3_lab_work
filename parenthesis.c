#include<stdio.h>

#include<string.h>

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

		printf("i am here\n");

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

int main()

{

	struct stack s;

	create(&s);

	int valid=1,i=0,j,pos,pos2=-1;

	char str[100],c,x;

	printf("enter expression:");

	scanf("%s",str);

	while(str[i]!='\0')

	{

	c=str[i++];

	if(c=='(' || c=='{' || c=='[')

		push(&s,c);

	if(c==')' || c=='}' || c==']')

		{

			if(s.top==-1)

				{

				valid=0;

				pos=i-1;

				break;

			}

			else

			{

				x=pop(&s);

				if((c-x)!=1 && (c-x)!=2)

				{

					valid=0;

					pos=i-1;

					break;

				}

			}

		}

	}

	if(s.top!=-1)

	{

		valid=0;

		pos2=strlen(str)-1;

	}

	if(valid==1)

		printf("string is valid\n");

	else

	{

		printf("string is invalid\n");

		if(pos2>pos)

			printf("error at position %d\n",pos2);

		else

			printf("error at position %d\n",pos+1);

	}

	return 0;

}

