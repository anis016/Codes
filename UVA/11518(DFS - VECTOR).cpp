#include<stdio.h>
#include<vector>
using namespace std;
#define MAX 10001

int n, m, l, counter;
int visit[MAX];

vector<int> mat[MAX];

void DFS(int s)
{
	int i;

	if(visit[s] == 1)
		return ;

	visit[s] = 1;
	for(i = 0; i < mat[s].size(); i++)
		DFS(mat[s][i]);
}

void init()
{
	int i;
	for(i = 1; i <= n; i++)
		visit[i] = 0;

	for(i = 0; i < n; i++)
		mat[i].clear();
}

int main()
{
	int i, Case;

	scanf("%d", &Case);
	while(Case--)
	{
		scanf("%d %d %d", &n, &m, &l);
		init();

		for(i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			mat[x].push_back(y);
		}

		int start;
		for(i = 0; i < l; i++)
		{
			scanf("%d", &start);
			DFS(start);
		}

		int count = 0;
		for(i = 1; i <= n; i++)
			if(visit[i] == 1)
				count++;

		printf("%ld\n", count);
	}

	return 0;
}