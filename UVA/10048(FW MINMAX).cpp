#include<stdio.h>
#include<string.h>
#define MAX 10000
#define INF 99999999

long mat[MAX][MAX], queryi[MAX];
long vertex, edge, query; 

struct query
{
	long sour;
	long dest;
}Q[MAX];

long min(long a, long b)
{
	if(a > b)
		return b;
	else
		return a;
}

long max(long a, long b)
{
	if(a > b)
		return a;
	else
		return b;
}

void init()
{
	long i, j;

	for(i=0; i<=vertex; i++)
		for(j=0; j<=vertex; j++)
			if( i == j)
				mat[i][j] = 0;
			else
				mat[i][j] = INF;

	return ;
}

void read_input()
{
	long i, x, y, wt;

	for(i=1; i<=edge; i++)
	{
		scanf("%ld %ld %ld", &x, &y, &wt);

		mat[x][y] = wt;
		mat[y][x] = wt;
	}

	for(i=0; i<query; i++)
		scanf("%ld %ld", &Q[i].sour, &Q[i].dest);

	return ;
}

void warshall(void )
{
	long i, j, k;

	 for(k = 1 ; k <= vertex; ++k)
		 for(i = 1 ; i <= vertex; ++i)
			 for(j = 1 ; j <= vertex; ++j)
				 mat[i][j] = min( mat[i][j], max(mat[i][k], mat[k][j]) ); 
	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	long cnt = 1, i;	
	
	while(scanf("%ld %ld %ld", &vertex, &edge, &query)==3)
	{
		if(!vertex && !edge && !query)
			break;
		
		init();
		read_input();

		warshall();

		if(cnt >1) 
			putchar('\n');

		printf("Case #%ld\n", cnt++);
		for(i=0; i<query; i++)
		{
			if(mat[Q[i].sour][Q[i].dest] >= INF)
				printf("no path\n");
			else
				printf("%ld\n", mat[Q[i].sour][Q[i].dest]);
		}
	}

	return 0;
}