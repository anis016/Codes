#include<stdio.h>
#include<string.h>
#define MAX 101

int mat[MAX][MAX];
int next, maxi;
int N, inc;

int R[] = { 0, -1, 0, 1};
int C[] = {-1,  0, 1, 0};

void DFS(int x, int y)
{
	int i;

	mat[x][y] = -1;
	for(i = 0; i < 4; i++)
	{
		int nr = R[i] + x;
		int nc = C[i] + y;

		if(nr < 0 || nc < 0 || nr > N || nc > N)
			continue;

		if(mat[nr][nc] == next)
		{
			maxi++;
			DFS(nr, nc);
		}
	}
}

int main()
{
	int i, j;

	char buf[65536];
	while(gets(buf)) 
	{
		if (sscanf(buf, "%d", &N) != 1) 
			continue;
		if (N == 0) 
			break;

		bool ok = true;
		memset(mat, 0, sizeof(mat));
				
		for (i = 1; i <= N-1; i++) 
        {
			gets(buf);
			for (char *p = buf; ok;) 
            {
				int x, y, d;
				if (sscanf(p, " %d %d %n", &x, &y, &d) < 2) 
                    break;
				p += d;

				if (x < 1 || y < 1 || x > N || y > N) 
                {
					ok = false;
					continue;
				}

				mat[x][y] = i;
			}
		}
		
		if(ok == false)
		{
			printf("wrong\n");
			continue;
		}
		
		for(i = 1; i <= N ; i++)
			for(j = 1; j <= N ; j++)
				if(mat[i][j] == 0)
					mat[i][j] = N;

		for(i = 1; i <= N && ok; i++)
		{
			for(j = 1; j <= N && ok; j++)
				if(mat[i][j]  != -1)
				{
					maxi = 1;
					next = mat[i][j];

					DFS(i, j);

					ok =  maxi == N;
				}
		}

		if(ok)
			printf("good\n");
		else
			printf("wrong\n");
	}
	return 0;
}