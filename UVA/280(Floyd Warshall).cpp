#include<stdio.h>
#define MAX 500

long mat[MAX][MAX], store[MAX+MAX];
long N, M, K, Z;
#define INF 100000

/* DFS TLE 
void explore(long start)
{
	long i;

	for(i=0; i<count[start]; i++)
	{
		if(mat[start][degree[start][i]] == 1 && visit[degree[start][i]] == 0)
		{
			visit[degree[start][i]] = 1;
			explore(degree[start][i]);
		}
	}
	return ;
}
*/

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

void inita(void)
{
	long i, j;

	for(i=0; i<=N; i++)
		for(j=0; j<=N; j++)
			mat[i][j]=INF;

	return ;
}

int main()
{
//	freopen("280.txt", "r", stdin);
//	freopen("2800.txt", "w", stdout);

	long i, init_point, j, k, cnt;
	
	while(scanf("%ld", &N) == 1 && N != 0)
	{
		inita();
		while(scanf("%ld", &M) == 1 && M != 0)
		{
			while(scanf("%ld", &K) == 1 && K != 0)
			{
				mat[M][K] = 1;
			}
		}
		floyd_warshall();

		scanf("%ld", &Z);
		for(i=0; i<Z; i++)
		{
			scanf("%ld", &init_point);

			cnt = 0;
			for(j=1, k=0; j<=N; j++)
				if(mat[init_point][j] >= INF)
				{
					store[k++] = j;
					cnt++;
				}
				printf("%ld", cnt);
				for(j=0; j<cnt; j++)
					printf(" %ld", store[j]);
				printf("\n");
		}
	}

	return 0;
}