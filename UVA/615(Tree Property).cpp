#include<stdio.h>
#define MAX 1000001
        
struct Node
{
	int x, y;
}T[MAX];

int vertex, edge, store[MAX];
struct Tree
{
	int A[MAX], P[MAX], rank[MAX];
	int i;

	void init()
	{
		for(i = 0; i <= vertex; i++)
			make_set(i);
		return ;
	}

	void make_set(int x)
	{
		A[x] = 0;
		P[x] = x;
		rank[x] = 0;

		return ;
	}

	int find_set(int x)
	{
		if(x != P[x])
			P[x] = find_set(P[x]);
		return P[x];
	}

	void Union(int x, int y)
	{
		x = find_set(x);
		y = find_set(y);

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

void init()
{
	int i;
	for(i = 0; i <= vertex; i++)
		store[i] = 0;
}

int main()
{
	int x, y, cnt = 1, max;

	max = -1;
	edge = vertex = 0;
	while(scanf("%d %d",&x, &y) == 2)
	{
		if(x == 0 && y == 0)
		{
			printf("Case %d is a tree.\n", cnt++);
			continue;
		}
		if(x < 0 && y < 0)
			break;

		if(x > max)
			max = x;
		if(y > max)
			max= y;

		store[x] = 1;
		store[y] = 1;

		T[edge].x = x;
		T[edge].y = y;
		edge++;
		
		while(scanf("%d %d",&x, &y) == 2)
		{
			if(!x && !y)
				break;

			if(x > max)
				max = x;
			if(y > max)
				max= y;

			store[x] = 1;
			store[y] = 1;

			T[edge].x = x;
			T[edge].y = y;
			edge++;
		}
		vertex = max;

		uf.init();

		int i, flag = 0;
		for(i = 0; i < edge; i++)
		{
			x = uf.find_set(T[i].x);
			y = uf.find_set(T[i].y);

			if(x != y)
				uf.Union(x, y);		
			else
			{
				flag = 1;
				break;
			}
		}

		if(flag == 1)
			printf("Case %d is not a tree.\n", cnt++);
		else
		{
			for(i = 1; i <= vertex; i++)
				uf.A[uf.find_set(uf.P[i])]++;

			int g = 0;
			for(i = 1; i <= vertex; i++)
			{
				if(store[i] == 1)
				{
					if(uf.A[i] != 0)
						g++;
				}

				if(g > 1)
				{				
					flag = 1;				
					break;
				}
			}

			if(flag == 1)
				printf("Case %d is not a tree.\n", cnt++);
			else
				printf("Case %d is a tree.\n", cnt++);
		}
		init();
		max = -1;
		edge = vertex = 0;
	}
	return 0;
}