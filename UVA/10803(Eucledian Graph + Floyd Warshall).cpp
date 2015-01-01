#include<stdio.h>
#include<math.h>
#define MAX 128
#define INFINITY 0xfffffff

int vertex;
struct List
{
	int x, y;
}G[MAX];
double mat[MAX][MAX];

void read_input()
{
	int i;
	for(i = 0; i < vertex; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		G[i].x = x;
		G[i].y = y;
	}
	return ;
}

long square(int x)
{
	return x * x;
}

long distance(int x1, int y1, int x2, int y2)
{
	return (square(x1 - x2) + square(y1 - y2) );
}

void make_coordinate()
{
	int i, j;
	for(i = 0; i < vertex - 1; i++)
		for(j = i + 1; j < vertex; j++)
		{
			double dist = distance(G[i].x, G[i].y, G[j].x, G[j].y);
			if(dist > 100)
				mat[i][j] = mat[j][i] = INFINITY;
			else
				mat[i][j] = mat[j][i] = sqrt(dist);
		}
}

void init_path()
{
	int i, j;
	for(i = 0; i <= vertex; i++)
		for(j = 0; j <= vertex; j++)
			mat[i][j] = INFINITY;
}

void Floyd_Warshall()
{
	int i, j, k;

	for(k = 0; k < vertex; k++)
		for(i = 0; i < vertex; i++)
			for(j = 0; j < vertex; j++)
				if(mat[i][k] != 0xffffff && mat[k][j] != 0xffffff)
					if(mat[i][k] + mat[k][j] < mat[i][j])
						mat[i][j] = mat[i][k] + mat[k][j];
}

double Find_Max()
{
	int i, j;

	double max = -1.00;
	for(i = 0; i < vertex; i++)
		for(j = 0; j < vertex; j++)
		{
			if(mat[i][j] >= 268435455)
			{
				max = -1.000;
				return max;
			}				

			else if(mat[i][j] - max > 0.00000)
				max = mat[i][j];
		}
	return max;
}

int main()
{
	int Case, cnt = 1;
	scanf("%d", &Case);

	while(Case--)
	{
		scanf("%d", &vertex);

		read_input();
		init_path();
		make_coordinate();
		Floyd_Warshall();
		double max = Find_Max();

		printf("Case #%d:\n", cnt++);

		if(max <= 0.00000)
			printf("Send Kurdy\n");
		else
			printf("%.4lf\n", max);
		
		printf("\n");
	}
	return 0;
}