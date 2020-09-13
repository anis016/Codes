#include<stdio.h>
#define max 10000
typedef long tall;

char ho, sp1, sp2;
tall i, K, k, Q, r;
tall ans;
tall n, m;

int main()
{
	char xx[max];
	tall test;

	gets(xx);
	sscanf(xx, "%ld", &test);

	for(i=0; i<test; i++)
	{
		ans=0;
		scanf("%c%c%ld %ld", &sp1, &ho, &m, &n);

		if(ho=='k' || sp1=='k')
		{
			if(m%2!=0 && n%2!=0)
			{
				ans=(m*n)/2+1;
				printf("%ld\n", ans);
			    ans=0;
			}
			else
			{
			    ans=(m*n)/2;
			    printf("%ld\n", ans);
			    ans=0;
			}
		}
		else if(ho=='Q' || sp1=='Q')
		{
			if(m<n)
				printf("%ld\n", m);
			else
				printf("%ld\n", n);
		}
		else if(ho=='K' || sp1=='K')
		{
			ans=0;
			ans=((m+1)/2) * ((n+1)/2);
			printf("%ld\n", ans);
			ans=0;
		}
		else if(ho=='r' || sp1=='r')
		{
			if(m<n)
				printf("%ld\n", m);
			else
				printf("%ld\n", n);
		}
}
	return 0;
}
