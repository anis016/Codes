#include<stdio.h>
#include<string.h>
#define MAX 900

char mat[MAX][MAX];
long maxr, maxc;
long x, y;

long R[] = {-1, 0, 1, 0};
long C[] = {0, 1, 0, -1};

void color(long xt, long yt)
{
	long nr, nc, i;

	mat[xt][yt] = '#';
	for(i=0; i<4; i++)
	{
		nr = R[i] + xt;
		nc = C[i] + yt;

		if(nr < 0 || nc < 0 || nr > maxr || nc > maxc)
			continue;

		if(mat[nr][nc] != '#' && mat[nr][nc] == ' ')
			color(nr, nc);
	}
	return ;
}

void init()
{
	long i, j;

	for(i=0; i<=maxr; i++)
		for(j=0; j<=maxc; j++)
			mat[i][j] = 0;
}

bool find_pos()
{
	long i, j;

	for(i=2; i < maxr; i = i + 4)
	{
		for(j=0; j<maxc; j++)
			if(mat[i][j] == '*')
			{
				mat[i][j] = ' ';

				x = i;
				y = j;

				return true;
			}
	}

	return false;
}

void read_input()
{
	long i = 0;
	long len = -10000;
	
	while(1)
	{
		gets(mat[i]);		
		len = strlen(mat[i]);

		if(mat[i][0] == '_')
			break;		
		i++;
		if(len > maxc)
			maxc = len;
	}
	maxr = i;
	return ;
}

void print()
{
	long i;
	for(i=0; i<=maxr; i++)
		printf("%s\n", mat[i]);

	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	char xy[MAX];
	long Case;

	gets(xy);
	sscanf(xy, "%ld", &Case);

	while(Case--)
	{
		read_input();
		bool flag = find_pos();

		color(x, y);
		print();
	//	init();
		maxc = maxr = x = y = 0;
	}
	return 0;
}