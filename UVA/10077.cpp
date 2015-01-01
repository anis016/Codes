#include<stdio.h>

typedef long tall;

tall m, n;

int main()
{
	while(scanf("%lld %lld", &m, &n)!=EOF)
	{
		if(m==1 && n==1)
			break;
		else
		{
			while(m!=n)
			{
				if(m<n)
				{
					printf("L");
					n=n-m;
				}
				else
				{
					printf("R");
					m=m-n;
				}
			}
			printf("\n");
		}
	}
	return 0;
}