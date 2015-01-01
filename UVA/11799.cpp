/*
#include<stdio.h>
#include<algorithm>
using namespace std;
long mat[10000];
int main()
{
	long T, N, i, j;

	scanf("%ld", &T);
	for(i=1; i<=T; i++)
	{
		scanf("%ld", &N);
		for(j=0; j<N; j++)
			scanf("%ld", &mat[j]);
		sort(mat, mat + N);
		printf("Case %ld: %ld\n", i, mat[N - 1]);
	}
	return 0;
}
*/

#include<stdio.h>

int main()
{
	long T, N, i, j, mat, max;

	scanf("%ld", &T);
	for(i=1; i<=T; i++)
	{
		scanf("%ld", &N);
		max = -1;
		for(j=0; j<N; j++)
		{
			scanf("%ld", &mat);
			if(mat > max)
				max = mat;
		}
		
		printf("Case %ld: %ld\n", i, max);
	}
	return 0;
}
