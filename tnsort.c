#include<stdio.h>
int main()	//starting main method
{
	int i,j,n,k,m,l=0,s=0,c=0;
	printf("enter array length :");
	scanf("%d",&n);
	int a[n];
	printf("enter array elements,separated by a newline:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);	//taking input from the user
	if(n%2==0)
		k=n/2;
	else
		k=n/2+1;
	m=k;
	int large[k],small[k];
	for(i=0;i<n;i=i+2)
	{
		if(a[i]>a[i+1])
		{
			c++;
			large[l++]=a[i];	//sorting elements into two smaller arrays,one for calculating largest number and the other for smallest number
			small[s++]=a[i+1];
		}
		else
		{
			large[l++]=a[i+1];
			small[s++]=a[i];
		}
	}
	if(n%2!=0)
	{
		large[k-1]=a[n-1];
		small[k-1]=a[n-1];
	}
	while(k!=1)	//finding out largest element
	{
		for(i=0;i<(k-1);i++)
		{
			if(large[i+1]>large[i])
			{
				c++;
				large[i]=large[i+1];
			}
			for(j=i+1;j<(k-1);j++)
				large[j]=large[j+1];
			k--;
		}
	}
	while(m!=1)	//finding out smallest element
	{
		for(i=0;i<(m-1);i++)
		{
			if(small[i+1]<small[i])
			{
				c++;
				small[i]=small[i+1];
			}
			for(j=i+1;j<(m-1);j++)
				small[j]=small[j+1];
			m--;
		}
	}

	printf("largest element =%d\n",large[0]);	//printing result
	printf("smallest element =%d\n",small[0]);
	printf("no. of comparisons =%d\n",c);
	return 0;
}	//end of main function


