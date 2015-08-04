#include<stdio.h>
int T=0;
void shiftup(int a[][3],int c)
{
int p,t1,t2,t3;
while(c>0)
{
p=c/2;
if(a[c][0]>a[p][0])
return;
if(a[c][1]>=a[p][1])
return;
t1=a[c][0];
t2=a[c][1];
t3=a[c][2];
a[c][0]=a[p][0];
a[c][1]=a[p][1];
a[c][2]=a[p][2];
a[p][0]=t1;
a[p][1]=t2;
a[p][2]=t3;
c=p;
}
}
void rearrange(int a[][3],int n)
{
int i,t1,t2,t3,j;
for(i=0;i<(n-1);i++)
{
	
	for(j=i+1;j<n;j++)
	{
		if(a[j][0]<a[i][0])
		{
			t1=a[i][0];
			t2=a[i][1];
			t3=a[i][2];
			a[i][0]=a[j][0];
			a[i][1]=a[j][1];
			a[i][2]=a[j][2];
			a[j][0]=t1;
			a[j][1]=t2;
			a[j][2]=t3;
		}
	}
}
for(i=0;i<(n-1);i++)
{
	
	for(j=i+1;j<n;j++)
	{
		if(a[j][0]>T)
			continue;
		if(a[j][1]<a[i][1])
		{
			t1=a[i][0];
			t2=a[i][1];
			t3=a[i][2];
			a[i][0]=a[j][0];
			a[i][1]=a[j][1];
			a[i][2]=a[j][2];
			a[j][0]=t1;
			a[j][1]=t2;
			a[j][2]=t3;
		}
	}
}
}
int main()
{
int i,n,t1,t2;
printf("enter the number of jobs: ");
scanf("%d",&n);
int a[n][3];
for(i=0;i<n;i++)
{
printf("enter the arrival time of job %d: ",i+1);
scanf("%d",&a[i][0]);
printf("enter the required time of job %d: ",i+1);
scanf("%d",&a[i][1]);
a[i][2]=i+1;
shiftup(a,i);
}
for(i=0;i<n;i++)
{
printf("%d %d %d \n",a[i][0],a[i][1],a[i][2]);
}
int count=0;
rearrange(a,n);
while(a[0][1]!=0)
{
	t1=a[0][1];
	for(i=1;i<n;i++)
	{
		if(a[i][0]>T)
			break;
	}
	if(i<n && (a[i][0]-T)<t1)
	t1 =a[i][0]-T;
	a[0][1] -=t1;
	T=T+t1;
	if(a[0][1]==0)
	{
		printf("job %d completed at %d seconds \n",a[0][2],T);
		a[0][1]=a[n-1][1];
		a[0][0]=a[n-1][0];
		a[0][2]=a[n-1][2];
		n=n-1;
		}
	rearrange(a,n);
}
return 0;
}









































