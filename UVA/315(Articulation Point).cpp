#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define MAX 200
#define _min(u, v) u > v ? v : u

struct Vertex
{
	bool art, color;
	int child, parent, dfn, low;
}node[MAX];

int vertex, edge, timer;
vector<int>Link[MAX];

char xx[MAX*MAX];

void init()
{
	int i;
	for(i = 0; i <= vertex; i++)
	{
		Link[i].clear();
		node[i].color = false, node[i].parent = -1,	node[i].art = false, node[i].dfn = 0, node[i].low = 0, node[i].child = 0;
	}
}

void Art(int u)
{
	int w;

	node[u].color = true;
	node[u].art = false;
	node[u].dfn = node[u].low = ++timer;

	for(int i = 0; i < Link[u].size(); i++)
	{
		w = Link[u][i];
		if(node[w].color == false)
		{
			node[w].parent = u;
			node[u].child ++;

			Art(w);
			node[u].low = _min(node[u].low, node[w].low);

			if(node[u].parent == -1)
			{
				if(node[u].child > 1)
					node[u].art = true;
			}
			else if(node[w].low >= node[u].dfn)
				node[u].art = true;
		}
		else if(w != u)
			node[u].low = _min(node[u].low, node[w].dfn);
	}
}

int Cal()
{
	int i;

	timer = 0;
	for(i = 1; i <= vertex; i++)
	{
		if(node[i].color == false)
			Art(i);
	}
	
	int counter = 0;
	for(i = 1; i <= vertex; i++)
	{
		if(node[i].art == true)
			counter++;
	}

	return counter;
}

int main()
{
	while(gets(xx))
	{
		sscanf(xx, "%d", &vertex);
		if(!vertex)
			break;
		
		init();

		while(gets(xx))
		{
			int u = -1;
			if(strcmp(xx, "0") == 0 )
				break;

			char *p = strtok(xx, " ");
			while(p!=NULL)
			{
				char x[MAX] = {""};
				int v;

				strcpy(x, p);
				sscanf(x, "%d", &v);
				if(u == -1)
					u = v;
				else
				{
					Link[u].push_back(v);
					Link[v].push_back(u);
				}
				p = strtok(NULL, " ");
			}
		}

		int counter = Cal();
		printf("%d\n", counter);
	}
	return 0;
}
