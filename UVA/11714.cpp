#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long N;

	while(scanf("%ld", &N)==1)
	{
		long res = (N-1) + (long) (log10(N-1) / log10(2));
		printf("%ld\n", res);
	}
	return 0;
}