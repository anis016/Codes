#include<stdio.h>
#define MAX 41
typedef long long LL;

LL fibo[MAX + 20];
int store[100000001];

void generate()
{
	LL i;
	
	fibo[0]=0;
	fibo[1]=1;

	for(i = 2;i < MAX;i++)
		fibo[i]=fibo[i-1] + fibo[i-2];

	return ;
}

LL Bsearch(LL n)
{
	LL low, mid, high;

	low = 2;
	high = 40;

	while(low <= high)
	{
		mid = (low + high) / 2;

		if(fibo[mid] < n)
			low = mid + 1;
		else if(fibo[mid] > n)
			high = mid - 1;
		else
			return mid;
	}
	return mid;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	LL n, pos, flag, st, i, set, Case;

	generate();

	scanf("%lld", &Case);
	while(Case--)
	{
		scanf("%lld", &n);

		if(n == 0)
		{
			printf("0 = 0 (fib)\n");
			continue;
		}
		flag = 0;
		set = n;
		while(n)
		{
			pos = Bsearch(n);

			while(fibo[pos] > n)
				pos--;

			if(flag == 0)
				st = pos, flag = 1;
			
			store[fibo[pos]] = 1;
			n = n - fibo[pos];
		}
		
		printf("%lld = ", set);
		for(i = st; i > 1; i--)
		{
			printf("%lld", store[fibo[i]]);
			store[fibo[i]] = 0;
		}
		printf(" (fib)\n");
	}
	return 0;
}
