#include<stdio.h>
#define max 1000

long month[max];
long problem[max];

long sum, n, i, j, count;

int main()
{
	count=1;
	while(scanf("%ld", &month[0])==1)
	{
		if(month[0]<0)
			break;
		else
		{
			for(i=1; i<=12; i++)
				scanf("%ld", &month[i]);
			
			for(i=1; i<=12; i++)
				scanf("%ld", &problem[i]);
			
			sum=0;
			printf("Case %ld:\n", count++);

			for(j=0, n=1; j<12; n++, j++)
			{
				sum+=month[j];				
				if(sum>=problem[n])
				{
					printf("No problem! :D\n");
					sum=sum-problem[n];
				}
				else
					printf("No problem. :(\n");
			}
		}
	}
	return 0;
}