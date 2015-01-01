#include<stdio.h>
#define MAX 1000000

long hold[MAX], in, m, i, j,div,flag,tt;

int main()
{
	while(scanf("%ld %ld", &in, &m)==2)
	{
		flag=tt=0;
		hold[0]=in;
		i=1;
		
		if(in<m || m==1 || m==0)
			printf("Boring!\n");
		else
		{
			while(1)
			{
				j=in%m;
			
				if(j==0)
				{
					div=in/m;
					hold[i]=div;
					in=div;
					i++;
				}

				if(j!=0)
				{	
					flag=1;
					break;
				}
			}

			if(flag==1 && in!=1)
				printf("Boring!");
			else
			{
				tt=i;
				for(j=0; j<i; j++)
				{
					printf("%ld", hold[j]);
						if((tt-1)!=0)
							printf(" ");
								tt--;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
