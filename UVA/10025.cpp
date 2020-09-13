#include<stdio.h>
#include<math.h>
typedef long long LL;

int main()
{
	LL a, b, c, d, sum, root, n1, Case;
	
	scanf("%lld", &Case);
	while(Case--)
	{
		scanf("%lld", &sum);
		if(sum == 0)
		{
			printf("3\n");

			if(Case)
				printf("\n");

			continue;
		}

		if(sum < 0)
			sum = sum * -1;

		a = 1;
		b = 1;
		c = - 2 * sum;
		
		d = (b * b) - 4 * a * c;
		root = (LL)sqrt(d);
		
		n1 = (-b + root) / 2;

		LL N_sum;
		while(true)
		{
			N_sum = ( n1 * (n1 + 1) ) / 2;

			if( (N_sum - sum) % 2 == 0 && N_sum >= sum)
				break;
			else
				n1++;
		}

		printf("%lld\n", n1);

		if(Case)
			printf("\n");
	}

	return 0;
}