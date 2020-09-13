#include<stdio.h>
#include<algorithm>

#define MAX 8000
typedef long tall;
using namespace std;

int main()
{
	tall i, j=0;
	tall ways[MAX+10];
	tall coin[5]={50, 25, 10, 5, 1};
	tall n;

	fill(ways, ways+MAX+10, 0);               

	ways[0]=1;

	for(i=0; i<5; i++)
		for(j=coin[i]; j<=MAX; j++)
			ways[j]=ways[j]+ways[j-coin[i]];

	while(scanf("%lld", &n)!=EOF)
	{
		printf("%lld\n", ways[n]);
	}

	return 0;
}