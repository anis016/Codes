#include<stdio.h>

#define MAX 105
#define INF 0xfffffff
#define MIN(a, b) a > b ? b : a

int link[MAX][MAX], N, E;

void init() 
{
	int i, j;
	for(i = 1; i <= 100; i++) 
	{
		for(j = i; j <= 100; j++) 
		{
			if(i == j)
				link[i][j] = 0;
			else
				link[i][j] = link[j][i] = INF;
		}
	}
	return ;
}

void Floyd() 
{
	int i, j, k;
	for(k = 1; k<= N; k++) 
		for(i = 1; i <= N; i++) 
			for(j = 1; j <= N; j++) 
				link[i][j] = MIN(link[i][j], link[i][k] + link[k][j]);
	return ;
}

void process() 
{
	int equi_dist[MAX], inc, i, j;
	int max = 0, min = INF;
	bool flag;
	
	Floyd();
	
	inc = 0;
	for(i = 6; i <= N; i++) 
	{
		flag = true;
		for(j = 2; j <= 5; j++) 
		{
			if(link[i][j] != link[i][j-1] || link[i][j] == INF) 
			{
				flag = false;
				break;
			}
		}
		if(flag == true)
			equi_dist[inc++] = i;
	}
	for(i = 0; i < inc; i++) 
	{
		max = 0;
		int Co = equi_dist[i];
		for(j = 1; j <= N; j++)
			if(link[Co][j] > max) 
				max = link[Co][j];

		min = MIN(min,max);
	}
	min != INF ? printf("%d\n",min) : printf("-1\n");
}

int main() 
{
//	freopen("in.txt", "r", stdin);

	int Case, k = 1, u, v, c;

	scanf("%d",&Case);
	while(Case--) 
	{
		scanf("%d %d", &N, &E);
		
		init();

		while(E--) 
		{
			scanf("%d %d %d",&u, &v, &c);
			if(link[u][v] > c)
				link[u][v] = link[v][u] = c;
		}
		printf("Map %d: ",k++);
		process();
	}
	return 0;
}


