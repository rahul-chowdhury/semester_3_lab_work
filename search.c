#include<stdio.h>
void sequential(int *test,int *org)		//starting function to perform sequential search
{
	FILE *f=fopen("seq.txt","w");
	if(f==NULL)
	{
		printf("file cannot be opened");
		exit(1);
	}
	int c=0,i=0,j=0;
	for(i=0;i<201;i++)
	{
		for(j=0;j<101;j++)
		{
			c++;
			if(test[i]<org[j])
				break;
			if(org[j]==test[i])
				break;
		}
		fprintf(f,"%4d %5d\n",test[i],c);
	}
	fclose(f);
}
void binary(int *test,int *org)	//starting function to perform binary search
{
	FILE *f=fopen("bin.txt","w");
	if(f==NULL)
	{
		printf("file cannot be opened");
		exit(1);
	}
	int c=1,i=0,j=0,low,high,mid;
	for(i=0;i<201;i++)
	{
		low=0;
		high=100;
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
		fprintf(f,"%4d %5d\n",test[i],c);
	}
	fclose(f);
}
void interpolation(int *test,int *org)
{
	FILE *f=fopen("inter.txt","w");	//opening file
	if(f==NULL)
	{
		printf("file cannot be opened");
		exit(1);
	}
	int c=1,i=0,j=0,low=0,high=100,mid;
	for(i=0;i<201;i++)
	{
		low=0;high=99;
		while(low<=high && test[i]>=org[low] && test[i]<=org[high])	//performing interpolation search
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
		fprintf(f,"%4d %5d\n",test[i],c);	//printing number of basic operations required in inter polation search to file
	}
	fclose(f);	//closing file
}
int main()
{
	int i,j;
	int org[100];
	for(j=0;j<100;j++)
		org[j]=10*(j+1);	//iniatilzing test cases
	int test[200];
	for(i=0;i<=200;i++)
		test[i]=5*(i+1);
	sequential(test,org);
	binary(test,org);
	interpolation(test,org);
	return 0;
}	//end of main() function
