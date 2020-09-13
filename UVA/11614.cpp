#include<stdio.h>
#include<math.h>

int main()
{
//	freopen("11614i.txt", "r", stdin);
//	freopen("11614o.txt", "w", stdout);

	long D, res, N, test;

	scanf("%ld", &test);
	while(test--)
	{
		scanf("%ld", &N);

		D = floor(sqrt(1 + 8*N));
		res = (-1 + D) / 2;

		printf("%ld\n", res);
	}
	return 0;
}