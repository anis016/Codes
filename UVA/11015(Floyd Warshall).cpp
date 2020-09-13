#include<stdio.h>
#include<string.h>
#define INF 100000
#define max 500

char str[max][15];
long mat[max][max];
long M, N;

void init(void )
{
	long i, j;

	for(i=0; i<=N; i++)
		for(j=0; j<=N; j++)
		{	
			mat[i][j] = INF;
		    mat[i][i] = 0;
		}
	return ;
}

void print(void )
{
	long i, j;

	for(i=1; i<=N; i++)
	{
		for(j=1; j<=N; j++)
			printf("%ld ", mat[i][j]);
		printf("\n");
	}
}


void read_Case(void )
{
	long i, j, cost, x, y;
	
	for(i=1; i<=N; i++)
		scanf("%s", str[i]);

	for(j=1; j<=M; j++)
	{
		scanf("%ld %ld %ld", &x, &y, &cost);
		mat[x][y] = cost;
		mat[y][x] = cost;
	}

	return ;
}

void floyd_warshall(void )
{
	long i, j, k;
	for(k=1; k<=N; k++)
		for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
				if(mat[i][k] + mat[k][j] > mat[i][j])
					mat[i][j] = mat[i][j];
				else
					mat[i][j] = mat[i][k] + mat[k][j];
	return ;
}

long find_min(void )
{
	long min = 100 * INF;
	long i, j, res, d;

	res = 0;
	for(i=1; i<=N; i++)
	{
		res = 0;
		for(j=1; j<=N; j++)
		{
			res += mat[i][j];
		}
		if(res < min)
		{
			min = res;
			d = i;
		}
	}
	return d;
}

int main()
{
	long l, i, Case = 1, x, y, cost;

	while(scanf("%ld %ld", &N, &M), N)
	{
		if(M==1)
		{
			for(i=1; i<=N; i++)
				scanf("%s", str[i]);
			scanf("%ld %ld %ld", &x, &y, &cost);
			printf("Case #%ld : %s\n", Case++, str[x]);

			continue;
		}

		init();
		read_Case();		
		floyd_warshall();
		l = find_min();
		printf("Case #%ld : %s\n", Case++, str[l]);
	}
	return 0;
}