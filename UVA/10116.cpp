#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4789)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<ctime>
#include<stack>
using namespace std;

#define eps 1e-8
#define pinf (1<<30)
#define ninf -1*pinf
#define pi (2*acos(0.0))
//typedef long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}
typedef pair<int, int>ii;

#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))
#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

#define MAX 50
int maxrow, maxcol;
int stx, sty, col;
char mat[MAX][MAX];
int cnt[MAX][MAX];
int visit[MAX][MAX];

struct Point
{
	char pos;
	int x, y;
}point[90];

void initp()
{
	point['N'].pos = 'N';
	point['N'].x   = -1, point['N'].y   =  0;
	point['S'].pos = 'S';
	point['S'].x   =  1, point['S'].y   =  0;
	point['E'].pos = 'E';
	point['E'].x   =  0, point['E'].y   =  1;
	point['W'].pos = 'W';
	point['W'].x   =  0, point['W'].y   = -1;
}

void read_input()
{
	int i, j;
	for(i = 0; i <= maxrow; i++)
	{
		getchar();
		for(j = 0; j <= maxcol; j++)
		{
			scanf("%c", &mat[i][j]);
			visit[i][j] = 0;
			cnt[i][j]   = 1;
		}
	}
	return ;
}

void init()
{
	int i, j;
	for(i = 0; i<= maxrow; i++)
	{
		for(j = 0; j <= maxcol; j++)
		{
			mat[i][j] = '0';
			cnt[i][j] = 0;
			visit[i][j] = 0;
		}
	}
	return ;
}

int main () 
{
	initp();

	while(scanf("%d %d %d", &maxrow, &maxcol, &col)==3)
	{
		if(!maxrow && !maxcol && !col)
			break;
		
		maxrow--, maxcol--, col--;
		read_input();

		int ux, uy, prevx, prevy, flag = 0, stx = 0, sty = col;
		stack<ii>S;

		S.push(make_pair(stx, sty));
		while(!S.empty())
		{
			ii Top = S.top();
			S.pop();

			int x = Top.first;
			int y = Top.second;
			prevx = x, prevy = y;

			if(x < 0 || x > maxrow || y < 0 || y > maxcol)
			{
				flag = 2;
				printf("%d step(s) to exit\n", cnt[ux][uy]);
				break;
			}
			else
			{
				visit[x][y] = 1;
				
				int nx = x + point[mat[x][y]].x;
				int ny = y + point[mat[x][y]].y;
			
				if(visit[nx][ny] == 1)
				{
					printf("%d step(s) before a loop of %d step(s)\n", cnt[nx][ny] - 1, cnt[x][y] - cnt[nx][ny] + 1);
					break;
				}
				cnt[nx][ny] = 1 + cnt[prevx][prevy];
				mat[x][y]  = '0';

				S.push(make_pair(nx, ny));
				ux = x, uy = y;
			}
		}
		init();
	}
    return 0;
}
