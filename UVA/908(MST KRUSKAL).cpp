#include<stdio.h>
#include<stdlib.h>

#define MAX 1000010

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

long read_input()
{
	long i;
	long x, y, wt, total;

	edge = vertex - 1;

	total = 0;
	for(i=0; i<edge; i++)
	{
		scanf("%ld %ld %ld", &x, &y, &wt);

		G[i].x = x;
		G[i].y = y;
		G[i].wt = wt;

		total += G[i].wt;
	}
	
	return total;
}

long kruskal()
{
	long total, i;

	for(i=1; i<=vertex; i++)
		MAKE_SET(i);

	qsort((void *)G, edge, sizeof(G[0]), sort_function);

	total = 0;
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

void new_read_input()
{
	long K, i, M;

	scanf("%ld", &K);

	edge = 0;

	edge = K;
	for(i=0; i < edge ; i++)
		scanf("%ld %ld %ld", &G[i].x, &G[i].y, &G[i].wt);

	scanf("%ld", &M);

	edge = edge + M;
	for(i=K; i<edge; i++)
		scanf("%ld %ld %ld", &G[i].x, &G[i].y, &G[i].wt);

	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	long i, total, total_n;

	for(i=1; scanf("%ld", &vertex)==1 && vertex > 0; i++)
	{
		if(i!=1)
			printf("\n");
		
		total = read_input();
		
		new_read_input();		
		total_n = kruskal();

		printf("%ld\n%ld\n", total, total_n);
	}

	return 0;
}