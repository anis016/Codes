#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 1010000

long vertex, edge;
struct List
{
	long x, y;
	long wt;
}G[MAX], R[MAX];

struct coord
{
	long x, y;
}list[MAX];

long p[MAX], A[MAX];

long parent(long x)
{
	if(p[x] == -1)
		return x;

	p[x] = parent(p[x]);
	return p[x];
}
int sort_function(const void *a, const void *b) 
{
	List *p = ( List *)a;
	List *q = ( List *)b;

	if( p->wt > q->wt) 
		return 1;
	else if(p->wt < q->wt) 
		return -1;

	return 0;
}

struct UnionFind
{
	long rank[MAX], P[MAX];
	long i;

	void init()
	{
		for(i = 0; i <= vertex; i++)
		{
			MAKE_SET(i);
			A[i] = 0;
			p[i] = -1;
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

long mod(long x)
{
	if(x < 0)
		return (x * -1) ;
	return x;
}

long sq(long x)
{
	return x * x;
}

long distance(long x1, long y1, long x2, long y2)
{
	return ( mod( sq( x1 - x2) ) + mod( sq( y1 - y2) ) );
}

void make_coordinate()
{
	long i, j;

	edge = 0;
	for(i = 0; i < vertex - 1; i++)
		for(j = i + 1; j < vertex; j++)
		{
			G[edge].x = i + 1;
			G[edge].y = j + 1;
			G[edge].wt = distance(list[i].x, list[i].y, list[j].x, list[j].y);
			edge++;
		}
}

void read_input()
{
	long i;
	long x, y;

	for(i=0; i<vertex; i++)
	{
		scanf("%ld %ld", &x, &y);

		list[i].x = x;
		list[i].y = y;
	}

	make_coordinate();

	return ;
}

int main()
{
	long i, t1, t2, cnt, distance, test = 1, Case, j;
	double road, rail_road;

	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld %ld", &vertex, &distance);
		
		read_input();
		
		uf.init();

		qsort((void *)G, edge, sizeof(G[0]), sort_function);

		road = 0.00;
		rail_road = 0.00;
		cnt = 0;
		for(i = 0, j = 0; i < edge; i++)
		{
			t1 = uf.FIND_SET(G[i].x); 
			t2 = uf.FIND_SET(G[i].y);

			if( t1 != t2 )
			{
				if(G[i].wt <= distance * distance)
				{
					R[cnt].x = G[i].x;
					R[cnt].y = G[i].y;
					
					cnt++;
					road += sqrt(G[i].wt + 0.00);
				}
				else
					rail_road += sqrt(G[i].wt + 0.00);

				uf.UNION(G[i].x, G[i].y);
			}
		}

		if(cnt == 0)
		{
			printf("Case #%ld: %ld %.0lf %.0lf\n", test++, vertex, road, rail_road);
			continue;
		}

		for(i = 0; i < cnt; i++)
		{
			t1 = parent(R[i].x);
			t2 = parent(R[i].y);

			if(t1 != t2)
				p[t1] = t2;
		}

		for(i = 1; i <= vertex; i++)
			A[parent(i)]++;

		cnt = 0;
		for(i = 1;i <= vertex; i++)
			if(A[i]!=0)
				cnt++;

		if(cnt <= 0)
			cnt = 1;

		printf("Case #%ld: %ld %.0lf %.0lf\n", test++, cnt, road, rail_road);
	}

	return 0;
}