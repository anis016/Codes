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
	long wt;
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
	long x, y, a, b;
	long i, j;

	scanf("%ld", &vertex);

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
			G[edge].wt = distance(list[i].u, list[i].v, list[j].u, list[j].v);
			edge ++;
		}

	return ;
}

int sort_function(const void *a, const void *b) 
{
	List *p = ( List *)a;
	List *q = ( List *)b;

	return ( p->wt - q->wt);
}

long kruskal()
{
	long i, j;

	qsort((void *)G, edge, sizeof(G[0]), sort_function);

	for(i=0, j=0; i<edge; i++)
	{
		if( FIND_SET(G[i].x) != FIND_SET(G[i].y) )
		{
			K[j].x = G[i].x;
			K[j].y = G[i].y;
			j++;

			UNION(G[i].x, G[i].y);
		}	
	}
	
	return j;
}

char www[MAX];

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	long Case, len, i;
	
	scanf("%ld", &Case);
	while(Case--)
	{
		read_input();
		len = kruskal();

		if(len == 0)
			printf("No new highways need\n");
		else
		{
			for(i=0; i<len; i++)
			printf("%ld %ld\n", K[i].x, K[i].y);
		}
		if(Case)
			printf("\n");
	}
	return 0;
}