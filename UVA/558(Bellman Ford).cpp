#include<stdio.h>
#define INF 0xfffffff
#define MAX 2000001

long vertex, edge, st;
long d[MAX];

struct Graph
{
	long x;
	long y;
	long wt;
}G[MAX];

void init_single_source()
{
	long i;
	for(i=0; i<=vertex; i++)
		d[i] = INF;

	d[st] = 0;

	return ;
}

void relax(long u, long v, long cost)
{
	if(d[v] > d[u] + cost)
		d[v] = d[u] + cost;

	return ;
}

bool bellman()
{
	long i, j;

	init_single_source();
	for(i=0; i<=vertex; i++)
		for(j=0; j<edge; j++)
			relax(G[j].x, G[j].y, G[j].wt);

	for(i=0; i<edge; i++)
		if(d[G[i].y] > d[G[i].x] + G[i].wt)
		{
			d[G[i].y] = d[G[i].x] + G[i].wt;
			return false;
        }
	
	return true;
}

void destroy()
{
	long i;

	for(i=0; i<=vertex; i++)
	{
		d[i] = 0;
	}
	return ;
}

void read_input()
{
	long i, x, y, wt, maxi;
	scanf("%ld %ld", &vertex, &edge);

	maxi = 0;
	for(i=0; i<edge; i++)
	{
		scanf("%ld %ld %ld", &x, &y, &wt);

		if(x > maxi)
			maxi = x;

		G[i].x = x;
		G[i].y = y;
		G[i].wt = wt;
	}
	st = maxi;
	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	bool flag;
	long Case;

	scanf("%ld", &Case);
	while(Case--)
	{
		st = 0;
		read_input();
		flag = bellman();

		if(flag == false)
			printf("possible\n");
		else
			printf("not possible\n");

		destroy();
	}
	return 0;
}
