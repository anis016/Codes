#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

#define MAX 100001

vector<int>sorted_nodes;
vector<int>V[MAX], RV[MAX];
bool visit[MAX];
int comp[MAX], counter[MAX];

int vertex, edge;

void init()
{
	int i;
	for(i = 0; i <= vertex; i++)
	{
		counter[i] = 0;
		comp[i] = 0;
		visit[i] = false;
		V[i].clear();
		RV[i].clear();
	}
}

void dfs(int u)
{
	size_t i;

	visit[u] = true;
	for(i = 0; i < V[u].size(); i++)
	{
		int k = V[u][i];
		if(visit[k] == false)
			dfs(k);
	}
	sorted_nodes.push_back(u);
}

void reverse_dfs(int u, int N) 
{
	int i;

	visit[u] = true;
	comp[u] = N;

	for(i = 0; i < RV[u].size(); i++)
	{
		int k = RV[u][i];
		if(!visit[k])
			reverse_dfs(k, N); 
	}
}

int main()
{
	int i, j, Case, cases = 0;

	scanf("%d", &Case);
	while(Case--)
	{
		scanf("%d %d", &vertex, &edge);

		init();

		while(edge--)
		{
			int x, y;
			scanf("%d %d", &x, &y);

			V[x].push_back(y);
			RV[y].push_back(x);
		}

		for(i = 1; i <= vertex; i++)
		{
			if(!visit[i])
				dfs(i);
		}
		
		for(i = 0; i <= vertex; i++)
			visit[i] = false;

		int c = 0;
		for(i = sorted_nodes.size() - 1; i >= 0 ; i--)
		{
			j = sorted_nodes[i];
			if(!visit[j])
			{
				reverse_dfs(j, ++c);
			}
		}

		for(i = 1; i <= vertex; i++ ) 
		{
			for(j = 0; j < V[i].size (); j++)
				if( comp[i] != comp[V[i][j]] ) 
					counter[comp[V[i][j]]]++;
		}

		int cnt = 0;
		for(i = 1; i <= c; i++)
			if(counter[i] == 0)
				cnt++;

		printf("Case %d: %d\n", ++cases, cnt);
	}
	return 0;
}