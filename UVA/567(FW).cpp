#include<stdio.h>
#include<iostream>
using namespace std;

#define MAX 50
#define INFINITY 100000000

long A[MAX][MAX];

void init(void)
{
	long i, j;

	for(i=0; i<=20; i++)
		for(j=0; j<=20; j++)
			A[i][j]=INFINITY;
}

long min(long st, long nd)
{
	if(st<nd)
		return st;
	else
		return nd;
}

void warshall(void)
{
	long i, j, k, first,  second;

	for(k=1; k<=20; k++)
			for(i=1; i<=20; i++)
				for(j=1; j<=20; j++)
				{
					first=A[i][j];
					second=A[i][k] + A[k][j];

					A[i][j]=min(first, second);
				}
	return ;
}

int main()
{
	long i, j, num, flag, source, counter=1, dest, path, Case;

	while(scanf("%ld", &num)==1)
	{
		init();

		flag=0;
		for(i=1; i<20; i++)
		{
			if(flag==1)
				scanf("%ld", &num);
			flag=1;

			for(j=0; j<num; j++)
			{
				scanf("%ld", &path);
				A[i][path]=1;
				A[path][i]=1;
			}
		}

		warshall();

		printf("Test Set #%ld\n", counter++);
		scanf("%ld", &Case);
		
		for(i=1; i<=Case; i++)
		{
			scanf("%ld %ld", &source, &dest);
			printf("%2ld to %2ld: %ld\n", source, dest, A[source][dest]);

		}
		printf("\n");
	}
	return 0;
}
