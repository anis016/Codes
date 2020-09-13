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

#define eps 1e-10
#define pinf (1<<31)
#define ninf -1*pinf
#define pi (2*acos(0.0))
//typedef long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))
#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)
#define MAX 128

//vector<int>graph[MAX];
int graph[MAX][MAX], edge[MAX];
int matchL[MAX], matchR[MAX];
bool seen[MAX];

int n, m;

struct ListD
{
	double x, y;
}pointD[MAX];

struct ListH
{
	double x, y;
}pointH[MAX];

void input()
{
	int i;
	double x, y;

	for(i = 0; i < n; i++)
	{
		scanf("%lf %lf", &x, &y);
		pointD[i].x = x; pointD[i].y = y;
		//graph[i].clear();
	}

	for(i = 0; i < m; i++)
	{
		scanf("%lf %lf", &x, &y);
		pointH[i].x = x; pointH[i].y = y;
		//graph[i+n].clear();
	}
	return ;
}

void Set(long d)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			double x = pointD[i].x - pointH[j].x;
			double y = pointD[i].y - pointH[j].y;

			double dis = sqrt(x*x + y*y);
			
			if(d > dis || (dis-d) <= eps)
				graph[j][edge[j]++] = i;
			//	graph[j].push_back(i);	
		}
	}
	return ;
}

bool bpm( int u )
{
	int i,v;
	for( i = 0; i < edge[u] ; i++ ) 
	{
		v = graph[u][i];
		if( seen[v] ) 
			continue;
		
		seen[v] = true;			
		if( matchR[v] < 0 || bpm( matchR[v] ) )
		{
			matchL[u] = v;
			matchR[v] = u;
			return true;
		}
	}
    return false;
}

int main()
{
	long i, s, d;
	while(scanf("%d %d %ld %ld",&n,&m,&s,&d)==4)
	{	
		memset( edge, 0, sizeof( edge ) );

		input();
		Set(s*d);
		
		memset( matchL, -1, sizeof( matchL ) );
		memset( matchR, -1, sizeof( matchR ) );
		int cnt = 0;
		for( i = 0; i < m; i++ )
		{
			memset( seen, 0, sizeof( seen ) );
			if( bpm( i ) ) 
				cnt++;
		}
		printf("%d\n", n - cnt);
	}

    return 0;
}

