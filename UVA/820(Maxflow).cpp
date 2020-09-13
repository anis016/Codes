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

#define UNDEFINED		 -1
#define MAX				120 
#define MAX_FLOW 1000000000

int C[MAX][MAX];
int F[MAX][MAX];
int list[MAX][MAX],counter[MAX];
int minFlow[MAX],parent[MAX];
int vertex, edge, sink, source;

void init(void)
{
	int i;
	for(i=0;i<=vertex;i++)
	{
		memset(C[i], 0, sizeof(int)*vertex);
		memset(F[i], 0, sizeof(int)*vertex);
	}
	memset(counter, 0, sizeof(int)*vertex);
	return;
}

void add_edge()
{
	int n = edge;
	int x, y, c;

	while(n--)
	{
		scanf("%d %d %d", &x, &y, &c);
		x--;
		y--;

		if(x == y)
			continue;

		C[x][y] += c;
		C[y][x] += c;

		list[x][counter[x]++] = y;
		list[y][counter[y]++] = x; // Necessary For residual graph
	}
	return ;
}

int findFlow()
{
	int q[MAX+2], head, tail;
	int i, v, nV, c;

	memset(minFlow, 0xFF, sizeof(int)*vertex);
	minFlow[source] = MAX_FLOW;
	q[1]	   = source;
	tail 	   = 1;
	head	   = 0;
	while(head != tail)
	{
		v = q[++head];
		if(v == sink) break;
		for(i=0;i<counter[v];i++)
		{
			nV = list[v][i];
			if(minFlow[nV] != UNDEFINED)
				continue;
			else
			{
				c = C[v][nV] - F[v][nV];
				if(c > 0)
				{
					minFlow[nV] = _min(minFlow[v],c);
					parent[nV]  = v;
					q[++tail]   = nV;
				}
			}
		}
	}
	if(minFlow[sink] == UNDEFINED)
		return 0;
	for(v=sink; v!=source; )
	{
		nV 			= parent[v];
		F[nV][v]   += minFlow[sink];
		F[v][nV]   -= minFlow[sink];
		v           = nV;
	}
	return minFlow[sink];
}

int max_flow()
{
	int res = 0;
	while(true)
	{
		int path_cap = findFlow();
		if(path_cap == 0)
			break;
		res += path_cap;
	}
	return res;
}

int main () 
{
//    Fin;

	int cnt = 1;
	while(scanf("%d", &vertex), vertex)
	{
		scanf("%d %d %d", &source, &sink, &edge);
		source--;
		sink--;
	
		init();
		add_edge();

		int flow_res = max_flow();
		printf("Network %d\n",cnt++);
	    printf("The bandwidth is %d.\n\n", flow_res);
	}
   return 0;
}
