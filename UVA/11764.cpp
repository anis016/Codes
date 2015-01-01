#include<stdio.h>

long jump;

int main()
{
	long high, low, temp, Case, test, j, i;

	scanf("%ld", &test);
	for(i=1; i<=test; i++)
	{
		scanf("%ld", &Case);
		high = low = temp = 0;
		for(j=1; j<=Case; j++)
		{
			scanf("%ld", &jump);
			if(j>=2)
			{
				if(jump>temp)
				{
					high++;
					temp = jump;
				}
				else if(jump<temp)
				{
					low++;
					temp = jump;
				}
				else
					temp = jump;
			}
			else
			{
				temp = jump ;
			}
		}

		printf("Case %ld: %ld %ld\n", i, high, low);
	}
	return 0;
}