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
//typedef long long long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

#define MAX 10001
//#define MAX 50

int edge, vertex;
vector<int>V[MAX];
bool visit[MAX];

struct Graph
{
	int degree;
}G[MAX];

void init()
{
	int i;
	for(i = 0; i <= vertex; i++)
	{
		G[i].degree = 0;
		visit[i] = false;
		V[i].clear();
	}
}

void input()
{
	while(edge--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
	
		V[x].push_back(y);
		G[x].degree++;
		G[y].degree++;
	}
	return ;
}

bool _isconnected(int source)
{
	size_t i;
	int c = 1;
	queue<int>Q;
	
	Q.push(source);
	visit[source] = true;
	while(!Q.empty())
	{
		int top = Q.front();
		Q.pop();

		for(i = 0; i < (int)V[top].size(); i++)
		{
 			int k = V[top][i];
			if(visit[k] == false)
			{
				c++;
				if(c == vertex) 
					return true;
				Q.push(k);
			}
		}
	}

	return false;
}

int main()
{
//	Fin;

	while(scanf("%d %d", &vertex, &edge)==2)
	{
		if(edge == 0)
		{
			printf("Not Possible\n");
		    continue;
		}

		init();
		input();

		int i;

		int flag = 0;
		for(i = 0; i<vertex; i++) 
			if(G[i].degree % 2 != 0)
			{
				flag = 1;
				break;
			}

		if(flag == 1)
		{
			printf("Not Possible\n");
		    continue;
		}

		if(_isconnected(0) == true)
			printf("Possible\n");
		else
			printf("Not Possible\n");
	}
	return 0;
}