#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

#define MAX 5000

long edge, vertex;

struct List
{
	long x;
	long y;
	double wt;
}G[MAX];

struct Deci
{
	double u;
	double v;
}list[MAX];

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

void MAKE_SET(long x)
{
	P[x] = x;
	rank[x] = 0;

	return ;
}

long FIND_SET(long x)
{
	if(x != P[x])
		P[x] = FIND_SET(P[x]);
	return P[x];
}

void UNION(long x, long y)
{
	x = FIND_SET(x);
	y = FIND_SET(y);
	
	if (x != y) 
	{
		if (rank[x] < rank[y]) 
			P[x] = y;

		else if (rank[x] > rank[y]) 
			P[y] = x;

		else 
		{ 
			P[x] = y; 
			++rank[y]; 
		}
	}
	return ;
}

void read_input()
{
	double x, y;
	long i, j;

	scanf("%ld", &vertex);
	for(i=0; i<vertex; i++)
	{
		scanf("%lf %lf", &x, &y);

		list[i].u = x;
		list[i].v = y;
	}

	edge = 0;
	for(i = 0; i < vertex - 1; i++)
		for(j = i + 1; j < vertex; j++ )
		{
			G[edge].x = i + 1;
			G[edge].y = j + 1;
			G[edge].wt = distance(list[i].u, list[i].v, list[j].u, list[j].v);
			edge ++;
		}

	return ;
}

int sort_function(const void *a, const void *b) 
{
	List *p = ( List *)a;
	List *q = ( List *)b;

	if( p->wt > q->wt) 
		return 1;
	else if(p->wt < q->wt) 
		return -1;

	return 0;
}


double kruskal()
{
	double total;
	long i;

	for(i=1; i<=vertex; i++)
		MAKE_SET(i);

	qsort((void *)G, edge, sizeof(G[0]), sort_function);

	total = 0.0;
	for(i=0; i<edge; i++)
	{
		if( FIND_SET(G[i].x) != FIND_SET(G[i].y) )
		{
			total += G[i].wt;
			UNION(G[i].x, G[i].y);
		}	
	}

	return total;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	long Case;
	double total;
	scanf("%ld", &Case);
//	getchar();
	while(Case--)
	{
		read_input();
		total = kruskal();
		printf("%.2lf\n", total);

		if(Case)
			printf("\n");
	}
	return 0;
}