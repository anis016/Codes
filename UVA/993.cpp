#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX 100
char store[MAX];

int main()
{
	long N, i, Case;

	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld", &N);

		if(N == 1)
		{
			printf("1\n");
			continue;
		}

		int j = 0;
		for(i = 9; i >= 2; i--)
		{
			if( (N % i) == 0)
			{
				store[j++] = i + '0';
				N = N / i;
			}
		}

		if(N > 1)
		{
			puts("-1");
			continue;
		}
		store[j] = '\0';

		sort(store, store + j);
		puts(store);
	}
	return 0;
}