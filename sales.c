#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int i,j,region,salesman,product,quantity,choice;
char data[100];
FILE *f,*f1;
f1=fopen("dummy","r+");
int performance[4][6],cost[8];
for(i=0;i<4;i++)
	for(j=0;j<6;j++)
		performance[i][j]=0;
	cost[0]=115;
	cost[1]=240;
	cost[2]=500;
	cost[3]=450;
	cost[4]=20;
	cost[5]=1000;
	cost[6]=960;
	cost[7]=300;
	f=fopen("data.txt","a");
	if(f==NULL)
	{
		printf("could not open file\n");
		exit(1);
	}
	while(1)
	{printf("****************************************************************MENU*********************************************************\n");
		printf("ENTER 1 FOR DATA ENTRY\nENTER 2 FOR VIEWING PERFORMANCE TABLE\nENTER 3 TO EXIT\nENTER YOUR CHOICE:");
		scanf("%d",&choice);
		printf("\f");
		if(choice>3)
		{
			system("clear");
			printf("INVALID ENTRY.TRY AGAIN");
			continue;
		}
		if(choice==3)
			break;
		if(choice==1)
		{
			system("clear");
			printf("ENTER DATA:");
			scanf("%s",data);
			int check=0;
			if(strlen(data)==8)
			{
				if(data[0]>=49 && data[0]<=52)
				{
					if(data[1]>=49 && data[1]<=54)
					{
						check=0;
						for(i=2;i<5;i++)
						{
							if(data[i]>=49 && data[1]<=56)
								check=1;
							else
								break;
						}
						if(check==1)
						{
							check=0;
							for(i=5;i<8;i++)
							{
								if(data[i]>=48 && data[1]<=57)
									check=1;
								else
									 break;
							}
						}
					}
				}
			}
			if(check==0)
			{
				system("clear");
				printf("INVALID ENTRY.TRY AGAIN");
				continue;
			}

			f=fopen("data.txt","a");
			if(f==NULL)
			{
				printf("could not open file\n");
				exit(1);
			}
			fprintf(f,"%d",atoi(data));
			fclose(f);
		}
		if(choice==2)
		{
			f=fopen("data.txt","r");
			if(f==NULL)
			{
				printf("could not open file\n");
				exit(1);
			}
			while(1)
			{
				if(feof(f))
				break;
				fscanf(f,"%1d%1d%3d%3d",&region,&salesman,&product,&quantity);
				performance[region-1][salesman-1] +=cost[product%10-1]*quantity;
			}
			system("clear");
			printf("*************************************************************PERFORMANCE TABLE********************************************************\n");
			printf("\tSALESMAN\tPERFORMANCE\n");
			for(i=0;i<3;i++)
			{
				printf("REGION%d\n",i+1);
				for(j=0;j<6;j++)
					printf("\tSALESMAN%d\tRs.%d\n",j+1,performance[i][j]);
			}
			char c;
			printf("PRESS 1 TO GO THE NEXT PAGE AND 2 TO GO THE MAIN MENU: ");
			scanf("%c",c);
			if(c=='1')
			{
				printf("*************************************************************PERFORMANCE TABLE********************************************************\n");
				printf("\tSALESMAN\tPERFORMANCE\n");
				system("clear");
				for(j=0;j<6;j++)
					printf("\tSALESMAN%d\tRs.%d\n",j+1,performance[3][j]);
			}
			fclose(f);
		}
	}
	return 0;
}

