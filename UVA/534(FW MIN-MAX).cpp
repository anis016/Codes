#include<stdio.h>
#include<math.h>
#define MAX 1000
#define INF 99999999.999999

struct Deci
{
	long u;
	long v;
}list[MAX];

double mat[MAX][MAX];

long vertex, edge; 

long P[MAX], rank[MAX];

double mod(double x)
{
	if(x < 0.00)
		return (x * -1.00) ;
	return x;
}

double sq(double x)
{
	return x * x;
}

double distance(double x1, double y1, double x2, double y2)
{
	return ( sqrt( mod( sq( x1 - x2) ) + mod( sq( y1 - y2) ) ) );
}

double min(double a, double b)
{
	if(a > b)
		return b;
	else
		return a;
}

double max(double a, double b)
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
				mat[i][j] = 0.0;
			else
				mat[i][j] = INF;

	return ;
}

void read_input()
{
	long x, y;
	long i, j;

	for(i=1; i<=vertex; i++)
	{
		scanf("%ld %ld", &x, &y);

		list[i].u = x;
		list[i].v = y;
	}

	edge = 0;
	for(i = 1; i <= vertex - 1; i++)
		for(j = i + 1; j <= vertex; j++ )
		{
			mat[i][j] = mat[j][i] = distance(list[i].u, list[i].v, list[j].u, list[j].v);
			edge ++;
		}

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
	long cnt = 1;
	
	while(scanf("%ld", &vertex)==1)
	{
		if(!vertex)
			break;
		
		init();
		read_input();
		warshall();

		printf("Scenario #%ld\nFrog Distance = %.3lf\n\n", cnt++, mat[1][2]);
	}

	return 0;
}