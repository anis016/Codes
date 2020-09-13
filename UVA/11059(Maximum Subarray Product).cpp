#include<stdio.h>
#define MAX 50
typedef long long LL;

LL num[MAX];

int main()
{
	LL max, pro, i, j, N, test=1;

	while(scanf("%lld", &N)==1)
	{
		
		for(i=0; i<N; i++)
			scanf("%lld", &num[i]);

		max = 0;
		for(i=0; i<N; i++)
		{
			pro = 1;
			for(j=i; j<N; j++)
			{
				pro = pro * num[j];
				if(max < pro)
					max = pro;
			}
		}
		printf("Case #%lld: The maximum product is %lld.\n\n", test++, max);
	}
	return 0;
}
