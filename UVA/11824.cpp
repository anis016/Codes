#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 41

int store[MAX];
long power(long base, long expo)
{
	if(expo == 0)
		return 1;

	if(base == 1)
		return 1;

	if(expo == 1)
		return base;

	long res = power(base, expo / 2);
	long ret = res * res;

	if(expo % 2 == 1)
		ret = ret * base;

	return ret;
}

int main()
{
	int Case, flag;
	int i, T, p;
	long sum;

	scanf("%d", &Case);
	while(Case--)
	{
		T = flag = 0;
		for(i = 0; ;i++)
		{
			scanf("%d", &store[i]);

			if(store[i] == 0)
				break;
		}

		T = i;
		sort(store, store + T);

		sum = 0;
		p = 1;
		for(i = T - 1; i >= 0; i--)
		{
			sum += 2 * power(store[i], p);
			p++;

			if(sum > 5000000)
			{
				flag = 1;
				break;
			}
		}

		if(flag == 1)
			printf("Too expensive\n");
		else
			printf("%ld\n", sum);
	}

	return 0;
}