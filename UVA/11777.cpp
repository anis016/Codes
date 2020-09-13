#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 30

long mark[MAX];

int main()
{
	long i, Case, t, term, sum;

	scanf("%ld", &Case);
	for(t=1; t<=Case; t++)
	{
		sum = 0;
		for(i=0; i<4; i++)
		{
			scanf("%ld", &term);
			sum+=term;
		}
		for(i=0; i<3; i++)
		{
			scanf("%ld", &mark[i]);
		}
		sort(mark, mark+i);
		sum = sum + (mark[2] + mark[1]) / 2;

		if(sum >= 90)
			printf("Case %ld: A\n", t);
		else if(sum >= 80 && sum < 90)
			printf("Case %ld: B\n", t);
		else if(sum >= 70 && sum < 80)
			printf("Case %ld: C\n", t);
		else if(sum >= 60 && sum < 70)
			printf("Case %ld: D\n", t);
		else if(sum < 60)
			printf("Case %ld: F\n", t);
	}

	return 0;
}