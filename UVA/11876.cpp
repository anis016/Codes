#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 64726

int a[MAX + MAX];

int NOD(int N)
{
	int i, cnt = 0;
	for(i = 1; i * i <= N; i++)
	{
		if(i * i == N)
			cnt += 1;
		else if(N % i == 0)
			cnt += 2;
	}
	return cnt;
}

void generate()
{
	int i;
	a[0] = 1;
	for(i = 1; i <= MAX; i++)
		a[i] = a[i - 1] + NOD(a[i - 1]);
	return ;
}

int bsearch(int N)
{
	int low, high, mid;

	low = 0;

	if(N > MAX)
		high = MAX;
	else
		high = N;

	while(low <= high)
	{
		mid = (low + high) / 2;

		if(N < a[mid])
			high = mid - 1;
		else if(N > a[mid])
			low = mid + 1;
		else if(N == a[mid])
			return mid;
	}
	return -1;

}

int main()
{
	int beg, end, i, f1, f2, Case, ii;
	generate();

	scanf("%d", &Case);
	for(ii = 1; ii <= Case; ii++)
	{
		scanf("%d %d", &beg, &end);
		
		for(i = beg; ;i++)	
		{
			f1 = bsearch(i);
			if(f1 == -1)
				continue;
			else
				break;
		}
		
		for(i = end; ;i--)
		{
			f2 = bsearch(i);
			if(f2 == -1)
				continue;
			else
				break;
		}

		printf("Case %d: %d\n", ii, f2 - f1 + 1);
	}

	return 0;
}