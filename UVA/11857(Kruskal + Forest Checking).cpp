#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4789)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<ctime>
#include<stack>
using namespace std;

#define eps 1e-8
#define pinf (1<<30)
#define ninf -1*pinf
#define pi (2*acos(0.0))
//typedef long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)
#define MAX 10100000

long vertex, edge;
long rank[MAX], P[MAX];

struct List
{
	long x, y;
	long wt;
}G[MAX];

int sort_function(const void *a, const void *b) 
{
	List *p = ( List *)a;
	List *q = ( List *)b;

	return( p->wt > q->wt);
}

struct UnionFind
{
	long i;

	void init()
	{
		for(i = 0; i <= vertex; i++)
			MAKE_SET(i);
		return ;
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

bool Visit[MAX];
int main()
{
//	Fin;
	long i;
	while(scanf("%ld %ld", &vertex, &edge) == 2)
	{
		if(!vertex && !edge)
			break;

		read_input();

		if(vertex == 0 || edge == 0)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}

		for(i = 0; i< vertex; i++)
		{
			uf.MAKE_SET(i);
			Visit[i] = false;
		}

		qsort((void *)G, edge, sizeof(G[0]), sort_function);

		long Max = 0, Maxedge = edge - 1;
		for(i = 0; i < edge && Maxedge; i++)
		{
			if(uf.FIND_SET(G[i].x) != uf.FIND_SET(G[i].y))
			{
				if(G[i].wt > Max)
					Max = G[i].wt;

				uf.UNION(G[i].x, G[i].y);
				Visit[G[i].x] = true;
				Visit[G[i].y] = true;

				Maxedge--;
			}
		}
		
		bool flag = false;
		for(i = 0; i < vertex; i++)
			if(Visit[i] == false)
			{
				flag = true;
				break;
			}

		if(flag == true)
			printf("IMPOSSIBLE\n");
		else
			printf("%ld\n", Max);
	}
	return 0;
}
