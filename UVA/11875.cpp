#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 1000

int a[MAX];
int main()
{
	int Case, ii, n, i;
	scanf("%d", &Case);
	for(ii = 1; ii <= Case; ii++)
	{
		scanf("%d", &n);
		for(i=0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);

		printf("Case %d: %d\n", ii, a[n / 2]);
	}

	return 0;
}