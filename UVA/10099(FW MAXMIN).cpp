#include<stdio.h>
#include<math.h>
#include<string.h>
#define INF -100000
#define MAXI 10000

long mat[MAXI][MAXI];
long vertex, edge;

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


void warshall(void )
{
	long i, j, k;

	 for(k = 1 ; k <= vertex; ++k)
		 for(i = 1 ; i <= vertex; ++i)
			 for(j = 1 ; j <= vertex; ++j)
				 mat[i][j] = max( mat[i][j], min(mat[i][k], mat[k][j]) ); 
	return ;
}

void read_Case(void )
{
	long i, cost, x, y;
	
	for(i=0; i<edge; i++)
	{
		scanf("%ld %ld %ld", &x, &y, &cost);

		mat[x][y] = cost;
		mat[y][x] = cost;
	}
	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	
	long sr, dest, min, res, query, cnt = 1;

	while(scanf("%ld %ld", &vertex, &edge)==2)
	{
		if(!vertex && !edge)
			break;

		init();
		read_Case();
		
		scanf("%ld %ld %ld", &sr, &dest, &query);
		warshall();
		min = mat[sr][dest] - 1;

		res = ceil( double(query) / double(min) );

		if( query > res * (mat[sr][dest]-1)) 
			res++;

		printf("Scenario #%ld\n", cnt++);
		printf("Minimum Number of Trips = %ld\n\n", res);
	}
	return 0;
}