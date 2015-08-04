#include<stdio.h>
int main()
{
	int i,j,u,v,m=0,n=0,r,l,c,f=0,a[1000][1000],max,min;
	printf("enter the dimension of the matrix:");
	scanf("%d",&r);
c=r;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("enter the element at a[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
			
		}
		

	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			
			printf("%d ",a[i][j]);
			
		}
		printf("\n");
		

	}
	max=min=a[0][0];

for(i=0;i<r;i++)
	{
		max=min=a[i][0];

		for(j=0;j<c;j++)
		{
			if(a[i][j]>max)
			{
			max=a[i][j];
			m=j;
			u=max;
			}
			if(a[i][j]<min)
			{
			min=a[i][j];
			n=j;
			v=min;
			}
		}
		for(l=0;l<r;l++)
		{
			if(a[l][m]<max)
			u=a[l][m];
		}
		
		if(u==max)
		{
		printf("\n saddle point %d",max);
		f=1;
		}
		for(l=0;l<r;l++)
		{
		if(a[l][n]>min)
		v=a[l][n];
		}
		if(v==min)
		{
			printf("saddle point is %d\n",min);
			f=1;
		}
		m=n=0;
		}
		if(f==0)
	printf("there is no saddle point\n");
	return 0;
	}	
			
			
		

	
