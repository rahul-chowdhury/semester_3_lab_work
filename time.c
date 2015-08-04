#include<stdio.h>
#include<time.h>
clock_t t;
int main()
{
FILE *f=fopen("data.ods","w");
int i=1,k;
while(i!=43)
{t=clock();
k=fibo(i);
t=clock()-t;
fprintf(f,"%d	%f\n",i,(float)t/CLOCKS_PER_SEC);
i++;
}
return 0;
}
int fibo(int i)
{
if(i==0)
return 0;
if(i==1)
return 1;
return fibo(i-1) +fibo(i-2);
}

