#include<stdio.h>


int main()
{
	long double N, max;

	while(scanf("%llf", &N)!=EOF)
	{
			if(N<0)
		break;
	else
	{ 
		max=((N+N*N)/2)+1;

		printf("%.0llf\n", max);
	}
	}

   return 0;
}