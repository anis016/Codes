#include<stdio.h>
#include<string.h>
#define MAX 30

long link[MAX][MAX];
long edge, node;
long map[MAX];

void init(void )
{
	long i, j;
	for(i=0; i<MAX; i++)
		for(j=0; j<MAX; j++)
		{
			link[i][j] = 10000;
			if(i==j)
				link[i][j] = 0;
		}

	node = 0;
}

void warshall(void )
{
	long i, j, k;

	for(k=0; k<node; k++)
		for(i=0; i<node; i++)
			for(j=0; j<node; j++)
				if( link[i][k] + link[k][j] < link[i][j] )
					link[i][j] = link[i][k] + link[k][j];
	return ;
}

void read_case(long t)
{
	long i, x, y;

	edge = t;
	node = 0;
	while(edge--)
	{
		scanf("%ld %ld", &x, &y);

		for(i=0; i<node; i++)
			if(map[i]!=x)
			{
				continue;
			}
			else
				break;

			if(i==node)
			{
				map[node] = x;
				x = node++;				
			}
			else
			{
				x = i;
			}

		for(i=0; i<node; i++)
			if(map[i]!=y)
			{
				continue;
			}
			else
				break;

			if(i==node)
			{
				map[node] = y;
				y = node++;				
			}
			else
			{
				y = i;
			}

		if(x!=y)
			link[x][y] = link[y][x] = 1;
	}
	return ;
}

long convert(long x)
{
	long i;

	for(i=0; i<node; i++)
		if(map[i]==x)
			return i;
		else
			continue;
	
	return -1;
}

int main()
{
	long i, Case, flag, count, ttl, test=0;
	long xx;

	while(scanf("%ld", &Case), Case)
	{
		init();
		read_case(Case);
		warshall();
		
		while(scanf("%ld %ld", &xx, &ttl)==2)
		{
			if(xx==0 && ttl==0)
				break;

			flag = convert(xx);
			if(flag==-1)
			{
				printf("Case %ld: %ld nodes not reachable from node %ld with TTL = %ld.\n",++test, node, xx, ttl);
				continue;
			}
			
			count = 0;
			for(i=0; i<node; i++)
				if(link[flag][i] > ttl)
					count++;
			printf("Case %ld: %ld nodes not reachable from node %ld with TTL = %ld.\n",++test, count, xx, ttl);
		}
	}	
	return 0;
}
