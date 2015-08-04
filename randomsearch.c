#include<stdio.h>
void sequential(int *test,int *org)
{
FILE *f=fopen("seq.txt","w");
if(f==NULL)
{
	printf("file cannot be opened");
	exit(1);
}
int c=0,i=0,j=0;
for(i=0;i<5000;i++)
{
	for(j=0;j<1000;j++)
	{
		c++;
		if(test[i]<org[j])
			break;
		if(org[j]==test[i])
			break;
	}
	fprintf(f,"%4d\t\t%7d\n",test[i],c);
}
fclose(f);
}

void binary(int *test,int *org)
{
printf("i am here\n");
FILE *f=fopen("bin.txt","w");
if(f==NULL)
{
	printf("file cannot be opened");
	exit(1);
}
int c=1,i=0,j=0,low,high,mid;
for(i=0;i<5000;i++)
{
	low=0;
	high=999;
	while(low<=high)
	{
		mid=(low+high)/2;
		c++;
		if(org[mid]==test[i])
			break;
		else if(test[i]<org[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	fprintf(f,"%4d\t\t%7d\n",test[i],c);
}
fclose(f);
}


void interpolation(int *test,int *org)
{
FILE *f=fopen("inter.txt","w");
if(f==NULL)
{
	printf("file cannot be opened");
	exit(1);
}
int c=1,i=0,j=0,low=0,high=100,mid;
for(i=0;i<5000;i++)
{
	low=0;high=999;
	while(low<=high && test[i]>=org[low] && test[i]<=org[high])
	{
		c++;
if(low==high)
mid=low;
else
{
mid=(test[i]-org[low])*(high-low)/(org[high]-org[low]);
mid+=low;
}
if(org[mid]==test[i])
break;
else if(test[i]<org[mid])
high=mid-1;
else
low=mid+1;
}
fprintf(f,"%4d\t\t%7d\n",test[i],c);
}
fclose(f);
}
int main()
{
int i,j;
int org[1000];
int temp;

for(j=0;j<1000;j++)
{org[j]=rand()%10000;
}
for(i=0;i<1000;i++)
{
for(j=0;j<1000;j++)
{
if(org[j+1]<org[j])
{
temp=org[j];
org[j]=org[j+1];
org[j+1]=temp;
}
}}
for(j=0;j<1000;j++)
{printf("%d\n",org[j]);
}

int test[5000];


for(i=0;i<=5000;i++)
{test[i]=rand()%10000;
}
for(i=0;i<5000;i++)
{
for(j=0;j<5000;j++)
{
if(test[j+1]<test[j])
{
temp=test[j];
test[j]=test[j+1];
test[j+1]=temp;
}
}}
sequential(test,org);

binary(test,org);

interpolation(test,org);
return 0;
}

