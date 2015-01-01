#include<stdio.h>
#include<stdlib.h>

#define MAX 200010

struct List
{
	long x;
	long y;
	long wt;
}G[MAX];

long vertex, edge;
long rank[MAX], P[MAX];

int sort_function(const void *a, const void *s)
{
	 List *c = (List *)a;
	 List *d = (List *)s;

	 return (c->wt - d->wt);
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

long kruskal()
{
	long i, total;

	for(i=0; i<=vertex; i++)
		MAKE_SET(i);

	qsort((void *)G, edge, sizeof(G[0]), sort_function);

	total = 0;
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

long read_input()
{
	long i;
	long x, y, wt, total;

	total = 0;
	for(i=0; i<edge; i++)
	{
		scanf("%ld %ld %ld", &x, &y, &wt);

		G[i].x = x;
		G[i].y = y;
		G[i].wt = wt;

		total += wt;
	}

	return total;
}

int main()
{
	long total, total_n;

	while(scanf("%ld %ld", &vertex, &edge)==2)
	{
		if(!vertex && !edge)
			break;
		
		total_n = read_input();		
		total = kruskal();

		printf("%ld\n", total_n - total);
	}
	return 0;
}