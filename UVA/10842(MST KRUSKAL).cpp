#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

#define MAX 50000

long edge, vertex, Total_N;

struct List
{
	long x;
	long y;
	long wt;
}G[MAX];

long P[MAX], rank[MAX];


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
	long i, x, y, wt;

	Total_N = 0;
	for(i=0; i<edge; i++)
	{
		scanf("%ld %ld %ld", &x, &y, &wt);

		G[i].x = x;
		G[i].y = y;
		G[i].wt = wt;

		Total_N = Total_N + G[i].wt;
	}

	return ;
}

int sort_function(const void *a, const void *s)
{
	 List *c = (List *)a;
	 List *d = (List *)s;

	 return (d->wt - c->wt);
}

void init()
{
	long i;
	for(i=0; i<vertex; i++)
		MAKE_SET(i);
	return ;
}

long kruskal()
{
	long total, min = 100000000;
	long i;

	init();

	qsort((void *)G, edge, sizeof(G[0]), sort_function);

	total = 0;
	for(i=0; i<edge; i++)
	{
		if( FIND_SET(G[i].x) != FIND_SET(G[i].y) )
		{
			if(min > G[i].wt)
			{
				min = G[i].wt;
			//	total += G[i].wt;
			}
			UNION(G[i].x, G[i].y);
		}
	}

	return min;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	long Case;
	long total, cnt =1;
	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld %ld", &vertex, &edge);

		read_input();
		total = kruskal();
		printf("Case #%ld: %ld\n", cnt++, total);
	}
	return 0;
}