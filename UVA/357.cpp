#include<stdio.h>
#include<string.h>
#include<algorithm>

#define MAX 30000
using namespace std;

int main()
{
	long long ways[MAX+10];
	long long coin[5] ={50, 25, 10, 5, 1};           /// 5 pennies
	long long i, j=0;
	long long n;

        fill(ways, ways+MAX+10, 0);
//	memset(ways, '0', sizeof(ways));             // what is the difference between fill and memset?????

	ways[0]=1;

	for(i=0; i<5; i++)
		for(j=coin[i]; j<=MAX; j++)
			ways[j] = ways[j]+ways[j-coin[i]];   //// notice about coin[i];

	while(scanf("%lld", &n)!=EOF)
	{
		if(ways[n]==1)
			printf("There is only 1 way to produce %lld cents change.\n", n);
		else
			printf("There are %lld ways to produce %lld cents change.\n", ways[n], n);
	}
	return 0;
}
