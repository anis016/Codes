#include<stdio.h>
#define MAX 21
#define MAXM 10000

long device[MAX], toggle[MAXM];
bool flag[MAX];

int main()
{
	long cap, i, n, m;
	long sum, res, count=1;

	while(scanf("%ld %ld %ld", &n, &m, &cap)==3)
	{
		if(n==0 && m==0 && cap==0)
			break;
		
		for(i=1; i<=n; i++)
			scanf("%ld", &device[i]);
		
		sum=res=0;
		for(i=1; i<=m; i++)
		{
			scanf("%ld", &toggle[i]);

			if(flag[toggle[i]]==false)
			{
				sum+=device[toggle[i]];

				if(res<sum)
					res=sum;
			}

			else
				sum-=device[toggle[i]];

			if(flag[toggle[i]]==false)
				flag[toggle[i]]=true;
			else
				flag[toggle[i]]=false;
		}

		if(res<0)
			res=0;

		if(res>cap)
		{
			printf("Sequence %ld\n", count++);
			printf("Fuse was blown.\n");
		}

		else
		{
			printf("Sequence %ld\n", count++);
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %ld amperes.\n", res);
		}

		printf("\n");

		for(i=0; i<=20; i++)
		{
			flag[i]=false;
			device[i]=0;
		}

		for(i=0; i<=m; i++)
			toggle[i]=0;
	}

	return 0;
}