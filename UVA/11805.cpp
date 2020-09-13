#include<stdio.h>
#define MAX 1000

long mat[MAX], n;

void init()
{
	long i;

	for(i=1; i<=n; i++)
		mat[i] = i;

	return ;
}

void kill()
{
	long i;
	for(i=1; i<=n; i++)
		mat[i] = 0;
	return ;
}

int main()
{
	long k, i, j, p, hold, Case, cnt = 1, diff;

	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld %ld %ld", &n, &k, &p);

		if(k > n)
			diff = k - n, i = diff;
		else
			i = k;
		
		init();

		j = 0;
		while(1)
		{
			if(j == p)
				break;

			if(i > n)
				i = 1;

			hold = mat[i];
			i++;
			j++;
		}
		if(mat[i] == 0)
			mat[i] = 1;

		printf("Case %ld: %ld\n", cnt++, mat[i]);
		kill();
	}

	return 0;
}