#include<stdio.h>

int main()
{
	long double i, j;

	for( ; ;)
	{
		scanf("%llf", &i);
		if(i==0)
			break;
		else
		{
			if(i<=100)
				printf("f91(%.0llf) = 91\n", i);
			else 
			{
				j=i-10;
				printf("f91(%.0llf) = %.0llf\n", i, j);
			}
		}

	}

	return 0;
}
