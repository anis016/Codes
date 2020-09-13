#include<stdio.h>

int main()
{
	long a[10],i,temp,flag;

	while(scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld",&a[8],&a[7],&a[6],&a[5],&a[4],&a[3],&a[2],&a[1],&a[0])==9)
	{
		i=temp=flag=0;
		for(i=0;i<=8;i++)
		{
			if(a[i]!=0)
				flag=1;
		}
		if(flag==0)
		{
			printf("0\n");
			continue;
		}

		for(i=8;i>=0;i--)
		{
			if(a[i]==0)
				continue;

			if(i==0)
			{
				if(temp==1)
				{
					if(a[i]<0)
						printf(" - %ld",-a[i]);
					else
						printf(" + %ld",a[i]);
				}
				else
				{
					if(a[i]<0)
						printf("%ld",a[i]);
					else
						printf("%ld",a[i]);
				}
				continue;

			}
			if(a[i]<0 && temp==0)
			{
				if(a[i]==-1 && i==1)
					printf("-x");
				else if(a[i]!=-1 && i==1)
					printf("%ldx",a[i]);
				else if(a[i]==-1 && i!=1)
					printf("-x^%ld",i);
				else
					printf("%ldx^%ld",a[i],i);
				temp=1;
				continue;
			}
			if(a[i]>0 && temp==0)
			{
				if(a[i]==1 && i==1)
					printf("x");
				else if(a[i]!=1 && i==1)
					printf("%ldx",a[i]);
				else if(a[i]==1 && i!=1)
					printf("x^%ld",i);
				else
					printf("%ldx^%ld",a[i],i);
				temp=1;
				continue;
			}
			if(a[i]<0 && temp==1)
			{
				if(a[i]==-1 && i==1)
					printf(" - x");
				else if(a[i]!=-1 && i==1)
					printf(" - %ldx",-a[i]);
				else if(a[i]==-1 && i!=1)
					printf(" - x^%ld",i);
				else
					printf(" - %ldx^%ld",-a[i],i);
				continue;
			}
			if(a[i]>0 && temp==1)
			{
				if(a[i]==1 && i==1)
					printf(" + x");
				else if(a[i]!=1 && i==1)
					printf(" + %ldx",a[i]);
				else if(a[i]==1 && i!=1)
					printf(" + x^%ld",i);
				else
					printf(" + %ldx^%ld",a[i],i);
				continue;
			}
		}
		printf("\n");
	}
	return 0;
}