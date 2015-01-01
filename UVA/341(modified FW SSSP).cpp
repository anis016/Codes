#include<stdio.h>
#define MAX 11
#define INF 99999999

long d[16][16], s[16][16];
long n;

void init(void)
{
	long i, j;

	for(i=0; i<=MAX; i++)
		for(j=0; j<=MAX; j++)
			d[i][j]=INF;

	for(i = 1; i <= n; i++)
		for(d[i][i] = 0, j = 1; j <= n; j++)
			s[i][j] = j;

	return ;
}

void all_pair()
{
	long i, j, k;

	for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					if ((d[i][k] + d[k][j]) < d[i][j]) 
                    {
						d[i][j] = d[i][k] + d[k][j];
						s[i][j] = s[i][k];
					}
	return ;
}

void read_case(void )
{
	long i, j, wt, de, x;
	for(j=1; j<=n; j++)
	{
		scanf("%ld", &x);
		for(i=1; i<=x; i++)
		{
			scanf("%ld %ld", &de, &wt);
			d[j][de] = wt;
		}
	}
	return ;
}

void print(void )
{
	long i, j;
	for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
				printf("%ld ", s[i][j]);
			printf("\n");
		}
}

void find_path(long x, long y)
{
	long k;
	for (k = x; ;k = s[k][y]) 
	{
		printf(" %d", k);
		if (k == y)
			break;
	}
	return ;
}

int main()
{
	long sour, dest, Case = 0;
	while(scanf("%ld", &n), n)
	{
		init();
		read_case();
		all_pair();
		
		scanf("%ld %ld", &sour, &dest);
		printf("Case %ld: Path =", ++Case);

		find_path(sour, dest);		
		
		printf("; %ld second delay\n", d[sour][dest]);
	}
	return 0;
}
