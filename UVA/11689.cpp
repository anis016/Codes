#include<stdio.h>

int main()
{
	long s, f, r, total, count, test;
	
	scanf("%ld", &test);
	while(test--)
	{
		scanf("%ld %ld %ld", &s, &f, &r);
		
		total = s + f;
		count = 0;
		while(total >= r)
		{
			count = count + (total / r);
			total = (total / r) + (total % r);
		}

		printf("%ld\n", count);
	}
	return 0;
}