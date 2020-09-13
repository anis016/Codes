#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define MAX 9

#define FORTH 1
#define LEFT 2
#define RIGHT 3

char mat[MAX][MAX];
int row, col;
int sx, sy, dx, dy;

char lim[] = { 'I', 'E', 'H', 'O', 'V', 'A', '#' };
int R[] = { 0, -1, 0};
int C[] = {-1,  0, 1};

void read_input()
{
	int i, j;

	scanf("%ld %ld", &row, &col);
	for(i=0; i<row; i++)
	{
		getchar();
		for(j=0; j<col; j++)
		{
			scanf("%c", &mat[i][j]);

			if(mat[i][j] == '@')
				sx = i, sy = j;
			else if(mat[i][j] == '#')
				dx = i, dy = j;
		}
	}

	return ;
}

int dir[MAX * MAX];
int flag = true;

void DFS(int x, int y, char ch, int level)
{
	int i;

	if( (mat[x][y] == '#') || (x == dx && y == dy) )
	{
		flag = false;
		return ;
	}

	for(i = 0; flag && i < 3; i++)
	{
		int nr = R[i] + x;
		int nc = C[i] + y;

		if(nr < 0 || nc < 0 || nr > row || nc > col)
			continue;

		if(mat[nr][nc] == ch)
		{
			mat[nr][nc] = '.';
			ch = lim[level];

			if( nr == x && nc < y )
				dir[level] = LEFT;
			else if( nr == x && nc > y )
				dir[level] = RIGHT;
			else if( nr < x && y == nc )
				dir[level] = FORTH;

			DFS(nr, nc, lim[level + 1], level + 1);
		}
	}

}

void print()
{
	for(int i = 0; i <= 5; i++)
	{
		if(dir[i] == 1)
			printf("forth ");
		else if(dir[i] == 2)
			printf("left ");
		else if(dir[i] == 3)
			printf("right ");

		dir[i] = 0;
	}
	printf( dir[6] == 1 ? "forth" : dir[6] == 2 ? "left" : "right");
	dir[6] = 0;

	printf("\n");
}

void init()
{
	int i, j;

	for(i = 0; i <= row; i++)
		for(j = 0; j <= col; j++)
			mat[i][j] = 0;
	flag = true;
}

int main()
{
	int Case;

	scanf("%d", &Case);
	while(Case--)
	{
		read_input();
		DFS(sx, sy, lim[0], 0);
		print();

		init();
	}
	return 0;
}
