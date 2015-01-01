#include<stdio.h>
#include<stdlib.h>
#define MAX 1000010

struct Graph
{
	long x;
	long y;
	long wt;
}G[MAX];

long vertex, edge;

struct UnionFind
{
	long rank[MAX], P[MAX], A[MAX];
	long i;

	void init()
	{
		for(i = 0; i < vertex; i++)
			MAKE_SET(i);
	}

	void MAKE_SET(long x)
	{
		P[x] = x;
		rank[x] = 0;
		A[x] = 0;

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

		if(x != y)
		{
			if(rank[x] > rank[y])
				P[y] = x;
			else
			{
				P[x] = y;
				if(rank[x] == rank[y])
					rank[y] = rank[y] + 1;
			}
		}
		return ;
	}
}uf;

int sort_function(const void *a, const void *b)
{
	Graph *p = (Graph *)a;
	Graph *q = (Graph *)b;

	return (q ->wt - p->wt);
}

void read_input()
{
	long i;
	for(i = 0; i < edge; i++)
	{
		scanf("%ld %ld %ld", &G[i].x, &G[i].y, &G[i].wt);

		G[i].x--;
		G[i].y--;
	}

	return ;
}

void Connected_Component()
{
	long i;

	uf.init();
	qsort((void *)G, edge, sizeof(G[0]), sort_function);
	
	long Max_PPA = G[0].wt;
	for(i = 0; i < edge; i++)
	{
		if(uf.FIND_SET(G[i].x) != uf.FIND_SET(G[i].y))
		{
			if(G[i].wt != Max_PPA)
				break;
			
			uf.UNION(G[i].x, G[i].y);
		}
	}
	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	long i;
	while(scanf("%ld %ld", &vertex, &edge)==2)
	{
		if(!vertex && !edge)
			break;
		
		read_input();
		Connected_Component();

		for(i = 0; i < vertex; i++)
			uf.A[uf.FIND_SET(i)]++;

		long max = 0;
		for(i = 0; i < vertex; i++)
			if(uf.A[i] > max)
				max = uf.A[i];

		printf("%ld\n", max);
	}
	return 0;
}