#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
#include<string.h>
#include<cstring>
#include<cstdlib>
using namespace std;

#define MAX 1000
int indegree[MAX + MAX];
int d[MAX + MAX];

int main()
{
	int vertex, edge, i;

	while(scanf("%d %d", &vertex, &edge)==2)
	{
		if(!vertex && !edge)
			break;
		
		memset(indegree, 0, sizeof(indegree));
		vector<int> link[MAX];

		for(i = 0; i <= vertex; i++)
			link[i].clear();

		for(i = 0; i < edge; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			link[x].push_back(y);

			indegree[y]++;
		}

		queue<int>Q;
		vector<int>List;

		for(i = 1; i <= vertex; i++)
			if(indegree[i] == 0)
				Q.push(i);

		memset(d, 0, sizeof(d));
	    int time = 0;

		while(!Q.empty())
		{
     	    time = time + 1;			
			int Top = Q.front();
			Q.pop();

			d[time] = Top;

	//		List.push_back(Top);
			for(i = 0; i < link[Top].size() ; i++)
			{
				indegree[link[Top][i]] = indegree[link[Top][i]] - 1;
				if(indegree[link[Top][i]] == 0)
					Q.push(link[Top][i]);
			}
		}

		printf("%d", d[1]);
		for(i = 2; i <= vertex; i++)
			printf(" %d", d[i]);
		printf("\n");
/*
		printf("%d", List[0]);
		for(i = 1; i < List.size(); i++)
			printf(" %d", List[i]);
		printf("\n");
*/
	}

	return 0;
}
