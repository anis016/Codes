#include<stdio.h>
#define MAX 10

int V[MAX][MAX], A[MAX * MAX];
int vertex;

void read_input()  
{
	V[1][2] = 1;  V[2][1] = 1;
	V[2][3] = 1;  V[3][2] = 1;
	V[5][2] = 1;  V[2][5] = 1;
	V[3][5] = 1;  V[5][3] = 1;
	V[1][5] = 1;  V[5][1] = 1;
	V[1][3] = 1;  V[3][1] = 1;
	V[5][4] = 1;  V[4][5] = 1;
	V[3][4] = 1;  V[4][3] = 1;

	return ;
}

void DFS(int s, int level)
{
	int i;

	A[level] = s;

	if(level == 8)
	{
		for(i = 0; i <= 8; i++)
			printf("%d", A[i]);
		printf("\n");
	}

	for(i = 1; i <= vertex; i++)
	{
		if(V[s][i] == 1 && V[i][s] == 1)
		{
			V[s][i] = V[i][s] = 0;
			
			DFS(i, level + 1);

			V[s][i] = V[i][s] = 1;
		}

	}
}

int main()
{
	vertex = 5;

	read_input();	
	DFS(1, 0);

	return 0;
}