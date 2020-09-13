#include<stdio.h>
#include<stdlib.h>
#define MAX 6000

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

long kruskal()
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
	return sum;
}

long find_second_best()
{
	long sum = 0x7fffffff;
	long i, j;

	for(i=0; i<edge; i++)
	{
		if(G[i].Mst == false)
			continue;

		uf.init();
		long cost = 0, size = 0;

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
	}
	
	return sum;
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

	long W1, W2, Case;

	scanf("%ld", &Case);
	while(Case--)
	{
		read_input();
		W1 = kruskal();
		W2 = find_second_best();

		if(W2 == 0x7fffffff)
			W2 = W1;

	//	destroy();

		printf("%ld %ld\n", W1, W2);
	}
	return 0;
}