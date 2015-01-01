#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 79801

long vertex, edge;
struct List
{
	long x;
	long y;
	long wt;
}G[MAX];

struct LIST
{
	char str[500];
	long ord;
}L[MAX];

int sort_function(const void *a, const void *s)
{
	 List *c = (List *)a;
	 List *d = (List *)s;

	 return (c->wt - d->wt);
}

int sort_string(const void *a, const void *s)
{
	 LIST *c = (LIST *)a;
	 LIST *d = (LIST *)s;

	 return (strcmp(c->str, d->str) );
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

long Bsearch(char *s)
{
	long low, high, mid, f;

	low = 0;
	high = vertex - 1;

	while(low <= high)
	{
		mid = ( low + high ) / 2;
		f = strcmp(s, L[mid].str);

		if(f < 0)
			high = mid - 1;
		else if(f > 0)
			low = mid + 1;
		else
			return L[mid].ord;
	}
}

void read_input()
{
	char u[MAX], v[MAX];

	long i;
	long x, y, wt;

	for(i=0; i<vertex; i++)
	{
		scanf("%s", L[i].str);
		L[i].ord = i + 1;
	}
	
	qsort((void *)L, vertex, sizeof(L[0]), sort_string);
	for(i=0; i<edge; i++)
	{
		scanf("%s %s %ld", u, v, &wt);

		x = Bsearch(u);
		y = Bsearch(v);

		G[i].x = x;
		G[i].y = y;
		G[i].wt = wt;
	}
	scanf("%s", u);

	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin); 

	long i, t1, t2, total, cnt;

	while(scanf("%ld %ld", &vertex, &edge)==2)
	{
		if(!vertex && !edge)
			break;

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
				uf.UNION(G[i].x, G[i].y);
				total = total + G[i].wt;
			}
		}

		for(i=1; i<=vertex; i++)
			 uf.A[uf.FIND_SET(uf.P[i])]++;

		cnt = 0;
		for(i=1; i<=vertex; i++)
			if(uf.A[i])
			{
				cnt++;
				if(cnt > 1)
					break;
			}

		if(cnt == 1)
			printf("%ld\n",total);
		else
			printf("Impossible\n");
	}

	return 0;
}