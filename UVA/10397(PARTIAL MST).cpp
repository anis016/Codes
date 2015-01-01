#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

#define MAX 300000
            
long edge, vertex, edge_conn;
long F[900][900];

struct List
{
	long x;
	long y;
	double wt;
}G[MAX];

struct Deci
{
	long u;
	long v;
}list[MAX];

struct Connect
{
	long x;
	long y;
}E[MAX];

struct Krusk
{
	long x;
	long y;
}K[MAX];

long P[MAX], rank[MAX];

long sq(long x)
{
	return x * x;
}

long distance(long x1, long y1, long x2, long y2)
{
	return ( sq( x1 - x2) + sq( y1 - y2)  );
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
	long x, y;
	long i, j;
	double weight;

	for(i=1; i<=vertex; i++)
		MAKE_SET(i);

	for(i=0; i<vertex; i++)
	{
		scanf("%ld %ld", &x, &y);

		list[i].u = x;
		list[i].v = y;
	}

	scanf("%ld", &edge_conn);
	for(i=0; i<edge_conn; i++)
	{
		scanf("%ld %ld", &E[i].x, &E[i].y);
		F[E[i].x][E[i].y] = 1;
	}

	for(i=0; i<edge_conn; i++)
	{
		if( FIND_SET(E[i].x) != FIND_SET(E[i].y) )
			UNION(E[i].x, E[i].y);	
	}

	edge = 0;
	for(i = 0; i < vertex - 1; i++)
		for(j = i + 1; j < vertex; j++ )
		{
			if(F[G[i+1].x][G[j+1].y] == 1)
			{
				F[G[i+1].x][G[j+1].y] = 0;
				continue;
			}

			G[edge].x = i + 1;
			G[edge].y = j + 1;

			weight = distance(list[i].u, list[i].v, list[j].u, list[j].v);
			
			G[edge].wt = sqrt(weight);
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
	else if( p->wt < q->wt)
		return -1;
	return 0;
}

double kruskal()
{
	long i;
	double total;

	qsort((void *)G, edge, sizeof(G[0]), sort_function);

	total = 0.0;
	for(i=0; i<edge; i++)
	{
		if( FIND_SET(G[i].x) != FIND_SET(G[i].y) )
		{
			total = total + G[i].wt;
			UNION(G[i].x, G[i].y);
		}	
	}
	
	return total;
}

char www[MAX];

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	double total;
	
	while(scanf("%ld", &vertex)==1)
	{
		read_input();
		total = kruskal();
		printf("%.2lf\n", total);
	}
	return 0;
}