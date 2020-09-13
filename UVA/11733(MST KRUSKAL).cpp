#include<stdio.h>
#include<stdlib.h>
#define MAX 200000

struct List
{
	long x;
	long y;
	long wt;
}G[MAX];

long vertex, edge, weight;

int sort_function(const void *a, const void *s)
{
	 List *c = (List *)a;
	 List *d = (List *)s;

	 return (c->wt - d->wt);
}

struct UnionFind
{
	long rank[MAX], P[MAX], A[MAX];
	long i;

	void init()
	{
		for(i=1; i<=vertex; i++)
		{
			MAKE_SET(i);
			A[i] = 0;
		}
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

void read_input()
{
	long i;
	long x, y, wt;

	for(i=0; i<edge; i++)
	{
		scanf("%ld %ld %ld", &x, &y, &wt);

		G[i].x = x;
		G[i].y = y;
		G[i].wt = wt;
	}

	return ;
}

int main()
{
/*	freopen("in.txt", "r", stdin);  */

	long i, t1, t2, cnt, total, counter = 1, Case;

	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld %ld %ld", &vertex, &edge, &weight);

		read_input();
		
		uf.init();

		qsort((void *)G, edge, sizeof(G[0]), sort_function);

		total = 0;
		for(i=0; i<edge; i++)
		{
			t1 = uf.FIND_SET(G[i].x); 
			t2 = uf.FIND_SET(G[i].y);

			if( t1 != t2 )
			{
				if(G[i].wt < weight)
				{
					uf.UNION(G[i].x, G[i].y);
					total = total + G[i].wt;
				}	
			}
		}

		for(i=1; i<=vertex; i++)
			 uf.A[uf.FIND_SET(uf.P[i])]++;

		cnt = 0;
		for(i=1; i<=vertex; i++)
			if(uf.A[i])
				cnt++;				

		total = total + (cnt * weight);
		printf("Case #%ld: %ld %ld\n", counter++, total, cnt);
	}

	return 0;
}