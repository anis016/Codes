#include<stdio.h>
#include<stdlib.h>
#define MAX 60000
#define INF 0x7fffffff

#define min(a, b) a = a < b ? a : b

struct List
{
	long x;
	long y;
	long wt;
	bool Mst;
}G[MAX];

long vertex, edge;

struct UnionFind
{
	long rank[MAX], P[MAX];
	long i;

	void init()
	{
		for(i=0; i<=vertex; i++)
			MAKE_SET(i);
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
	List *p = (List *)a;
	List *q = (List *)b;

	return (p ->wt - q->wt);
}

void kruskal()
{
	long i, j, sum;

	uf.init();

	qsort((void *)G, edge, sizeof(G[0]), sort_function);

	sum = 0;
	for(i=0, j=0; i<edge; i++)
	{
		if(uf.FIND_SET(G[i].x) != uf.FIND_SET(G[i].y))
		{
			sum += G[i].wt;	
			G[i].Mst = true;
			uf.UNION(G[i].x, G[i].y);
		}
		else
			G[i].Mst = false;
	}
	return ;
}

void find_second_best()
{
	long sum = INF;
	long i, j;
	long count = 0, size;

	for(i=0; i<edge; i++)
	{
		if(G[i].Mst == false)
			continue;

		uf.init();
		long cost = 0;
		size = 0;

		for(j=0; j<edge; j++)
		{
			if(i == j)
				continue;

			if(uf.FIND_SET(G[j].x) != uf.FIND_SET(G[j].y))
			{
				cost += G[j].wt;
				uf.UNION(G[j].x, G[j].y);
				size++;
			}
		}
		
 		if(size == vertex-1)
			sum = min(sum, cost);
		else
			count++;
	}

	if(sum != INF)
		printf("%ld\n", sum);
	else if(count == vertex - 1)
		printf("No second way\n");
	else
		printf("No way\n");
	
	return ;
}

void read_input()
{
	long i;

	scanf("%ld %ld", &vertex, &edge);
	for(i=0; i<edge; i++)
	{
		scanf("%ld %ld %ld", &G[i].x, &G[i].y, &G[i].wt);

		G[i].x--;
		G[i].y--;
		G[i].Mst = false;
	}

	return ;
}

void destroy()
{
	long i;
	for(i=0; i<=vertex; i++)
	{
		G[i].Mst = false;
		G[i].x = 0;
		G[i].y = 0;
		uf.P[i] = 0;
		uf.rank[i] = 0;
	}

	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	long Case, i;

	scanf("%ld", &Case);
	for(i=1; i<=Case; i++)
	{
		read_input();
		kruskal();
		printf("Case #%ld : ", i);
		find_second_best();
	}
	return 0;
}