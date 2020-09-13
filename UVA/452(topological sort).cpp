#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int TimeD[MAX], ComD[MAX], G[MAX][MAX], Vis[MAX], vertex, visit[MAX];

struct node
{
	int n;
	node *next;
}*list;

void read_input(char str[MAX])
{
	int len, i, u, v;

	char *p = strtok(str, " ");
	v = p[0] - 'A' + 1;
	Vis[v] = 1;

	if(v > vertex)
		vertex = v;

	p = strtok(NULL, " ");
	TimeD[v] = ComD[v] = atoi(p);

	p = strtok(NULL, " ");
	if( p == NULL)
		return ;

	len = strlen(p);
	for(i = 0; i < len && *p; i++)
	{
		if(p[i] >= 'A' && p[i] <= 'Z')
		{
			u = p[i] - 'A' + 1;
			
			if(u > vertex)
				vertex = u;

			Vis[u] = 1;
			G[u][v] = 1;
		}
	}
	return ;
}

void dfs(int n)
{
	int i;

	visit[n] = 1;
	for(i = 1; i <= vertex; i++)
	{
		if(G[n][i] == 1 && visit[i] == 0)
			dfs(i);
	}

	node *p;
	p = new node;
	
	p -> next = list;
	list = p;
	p ->n = n;
}

void toposort()
{
	int i;

	for(i = 1; i <= vertex; i++)
		visit[i] = 0;

	for(i = 1; i <= vertex; i++)
	{
		if(Vis[i] && visit[i] == 0)
			dfs(i);
	}
	return ;
}

int calculation()
{
	node *p = list;
	int u, i;
	while(p != NULL)
	{
		u = p ->n;

		for(i = 1; i <= vertex; i++)
		{
			if(G[u][i] == 1)
			{
				if(TimeD[u] + ComD[i] > TimeD[i])
					TimeD[i] = TimeD[u] + ComD[i];
			}
		}
		p = p ->next;
	}

	int max = -1;
	for(i = 1; i <= vertex; i++)
		if(max < TimeD[i])
			max = TimeD[i];

	return max;
}

void init()
{
	int i, j;
	for(i = 0; i <= vertex; i++)
	{
		for(j = 0; j <= vertex; j++)
			G[i][j] = 0;

		TimeD[i] = ComD[i] = Vis[i] = 0;
	}
	return ;
}

int main()
{
	char xx[MAX];
	int Case;

	gets(xx);
	sscanf(xx, "%d", &Case);

	gets(xx);
	while(Case--)
	{
		list = NULL;
		vertex = -1;
		while(gets(xx))
		{
			int len = strlen(xx);
			if(len != 0)
				read_input(xx);
			else 
				break;
		}

		if(vertex == -1)
			printf("\n");
		else
		{
			toposort();
			int max = calculation();
			printf("%d\n", max);

			init();
		}

		if(Case)
			printf("\n");
	}

	return 0;
}