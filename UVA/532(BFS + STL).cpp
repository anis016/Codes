#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
#define MAX 31

int L, R, C, sx, sy, sz, dx, dy, dz;
int mat[MAX][MAX][MAX];
char str[MAX][MAX][MAX];

int X[] = {0, 0, 1,-1, 0,  0};
int Y[] = {1,-1, 0, 0, 0,  0};
int Z[] = {0, 0, 0, 0, 1, -1};

typedef pair<int, int>ii;
typedef pair<ii, int>iii;
typedef pair<iii, int>st;
queue <st>Q;

void read_input()
{
	int z, i, j;

	for(z = 0; z < L; z++)
	{
		for(i = 0; i < R; i++)
		{
			getchar();
			for(j = 0; j < C; j++)
			{
				scanf("%c", &str[z][i][j]);

				if(str[z][i][j] == 'S')
					sx = i, sy = j, sz = z;
				else if(str[z][i][j] == 'E')
					dx = i, dy = j, dz = z;
			}
		}
		getchar();
	}
	return ;
}

void BFS(int x, int y, int z)
{
	int i, cnt = 0;

	Q = std::queue<st>();
	Q.push(st(iii(ii(x, y), z), 0) );
	while(!Q.empty())
	{
		st Top = Q.front();

		x   = Top.first.first.first;
		y   = Top.first.first.second;
		z   = Top.first.second;
		cnt = Top.second;

		Q.pop();

		if(x == dx && y == dy && z == dz)
			break;

		for(i = 0; i < 6; i++)
		{
			int nx = x + X[i];
			int ny = y + Y[i];
			int nz = z + Z[i];

			if(nz < 0 || nx < 0 || ny < 0 || nz >= L || nx >= R || ny >= C)
				continue;

			if(str[nz][nx][ny] == 'E')
			{
				mat[nz][nx][ny] = cnt + 1;
				printf("Escaped in %d minute(s).\n", mat[nz][nx][ny]);

				return ;
			}
			if(str[nz][nx][ny] == '.')
			{
				str[nz][nx][ny] = '#';
				Q.push(st(iii(ii(nx, ny), nz), cnt + 1) );
				mat[nz][nx][ny] = cnt + 1;
			}
		}
	}

	printf("Trapped!\n");
	return ;
}

int main()
{
	while(scanf("%d %d %d", &L, &R, &C)==3)
	{
		if(!L && !R && !C)
			break;
		
		read_input();
		BFS(sx, sy, sz);
	}
	return 0;
}