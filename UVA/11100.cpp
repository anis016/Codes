#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 1000010

long mat[MAX];
long n, K;

void read_input()
{
	long i;

	for(i=0; i<n; i++)
		scanf("%ld", &mat[i]);
	return ;
}

void find_max()
{
	long i;
	long cnt = 1;

	for(i=1; i<n; i++)
	{
		if(mat[i] == mat[i-1])
			cnt++;
		else
			cnt = 1;

		if(cnt > K)
			K = cnt;				
	}
	return ;
}

int main()
{
	long i, j;

	while(scanf("%ld", &n), n)
	{
		read_input();

        sort(mat, mat + n);

		K = 1;

		find_max();

		long row = K;
		long col = (long) ceil( (double)n / (double)row);
		long k = 0;

		printf("%ld\n", row);
		for(i = 0; i < row; i++)
		{
			k = i;
			for(j = 0; j < col; j++)
			{
				if(mat[k] != 0)
				{
					printf("%ld", mat[k]);
				}
				k = k + row;

				if(mat[k] != 0)
					printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}