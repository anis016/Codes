#include<stdio.h>
#include<stdlib.h>
#define MAX 25001

struct List
{
	long x;
	long y;
	long wt;
}G[MAX];

long vertex, edge, weight[MAX];

int sort_function(const void *a, const void *s)
{
	 List *c = (List *)a;
	 List *d = (List *)s;

	 return (c->wt - d->wt);
}

struct UnionFind
{
	long rank[MAX], P[MAX];
	long i;

	void init()
	{
		for(i=0; i<vertex; i++)
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
	long i, t1, t2, j, flag;

	while(scanf("%ld %ld", &vertex, &edge)==2)
	{
		if(!vertex && !edge)
			break;

		read_input();		
		uf.init();
		qsort((void *)G, edge, sizeof(G[0]), sort_function);

		flag = 0;
		for(i=0, j=0; i<edge; i++)
		{
			t1 = uf.FIND_SET(G[i].x); 
			t2 = uf.FIND_SET(G[i].y);

			if( t1 != t2 )
				uf.UNION(G[i].x, G[i].y);
			else 
			{
				flag = 1;
				weight[j++] = G[i].wt;
			}
		}

		if(flag == 1)
		{
			for(i=0; i<j; i++)
			{
				printf("%ld", weight[i]);

				if(i < j - 1)
					printf(" ");
			}
			printf("\n");
		}
		else
			printf("forest\n");

	}
	return 0;
}

/*

3 3
0 1 1
1 2 2
2 0 3
4 5
0 1 1
1 2 2
2 3 3
3 1 4
0 2 0
3 1
0 1 1
0 0

3
2 4
forest

If there are no cycles in the graph then output the text forest instead of numbers.