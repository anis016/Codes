#include<stdio.h>
#define MAX 27

bool visit[MAX][MAX], A[MAX];
int link[MAX][MAX];
int vertex, edge, Max_path;

void init()
{
	int i, j;
	for(i = 0; i < vertex; i++)
		for(j = 0; j < vertex; j++)
			link[i][j] = 0;
}

void init_visit()
{
	int i, j;
	for(i = 0; i < vertex; i++)
		for(j = 0; j < vertex; j++)
			visit[i][j] = 0;
}

void read_input()
{
	int i;
	for(i = 0; i < edge; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		link[x][y] = link[y][x] = 1;
	}
	return ;
}

void DFS(int s, int level)
{
	int i;

	if(level > Max_path)
		Max_path = level;

	for(i = 0; i < vertex; i++)
	{
	//	if(visit[s][i] == true)
	//		return ;

		if(link[s][i] == 1 && (visit[s][i] == false || visit[s][i] == false) )
		{
			visit[s][i] = visit[i][s] = true;
			DFS(i, level + 1);			
			visit[s][i] = visit[i][s] = false;
		}
	}
}

int main()
{
	while(scanf("%d %d", &vertex, &edge)==2)
	{
		if(!vertex && !edge)
			break;

		init();
		read_input();

		int max = -1, i;
		Max_path = 0;
		
		for(i = 0; i < vertex; i++)
		{
			init_visit();
			DFS(i, 0);

			if(Max_path > max)
				max = Max_path;
		}

		printf("%d\n", max);
	}
	return 0;
}