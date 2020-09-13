#include<stdio.h>
#include<algorithm>

#define MAX 30010
typedef long long tall;
using namespace std;

double x;
tall i, j=0;
tall ways[MAX+10];
tall coin[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
tall n;

int main()
{
	ways[0]=1;

	for(i=0; i<11; i++)
		for(j=coin[i]; j<=MAX; j++)
			ways[j]=ways[j]+ways[j-coin[i]];

	while(scanf("%lf", &x)!=EOF)
	{
		if(x==0.00)
			break;

		n = (100*x+1e-5);
		printf("%6.2lf%17lld\n", x, ways[n]);
	}

	return 0;
}