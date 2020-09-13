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
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

#define MAX 110
char str[MAX];
int maxcol, maxrow;
int mat[MAX][MAX];
char dir;
int stx, sty;
int tmpx, tmpy;
int cnt;

struct Point
{
	char pos;
	int x, y;
}point[MAX];

void init()
{
	point['N'].pos = 'N';
	point['N'].x   =  0, point['N'].y   = 1;
	point['S'].pos = 'S';
	point['S'].x   =  0, point['S'].y   = -1;
	point['E'].pos = 'E';
	point['E'].x   =  1, point['E'].y   =  0;
	point['W'].pos = 'W';
	point['W'].x   = -1, point['W'].y   =  0;
}

bool visit(char act)
{
	if(act == 'R')
	{
		     if(dir == 'N') dir = 'E';
		else if(dir == 'E') dir = 'S';
		else if(dir == 'S') dir = 'W';
		else if(dir == 'W') dir = 'N';
	}
	else if(act == 'L')
	{
		     if(dir == 'N') dir = 'W';
		else if(dir == 'E') dir = 'N';
		else if(dir == 'S') dir = 'E';
		else if(dir == 'W') dir = 'S';
	}
//	else if(mat[stx][sty] == -1) return true;

	else if(act == 'F')
	{
		tmpx = 0; tmpy = 0;
		     if(dir == 'N') { tmpx = stx + point['N'].x; tmpy = sty + point['N'].y; }
		else if(dir == 'E') { tmpx = stx + point['E'].x; tmpy = sty + point['E'].y; }
		else if(dir == 'S') { tmpx = stx + point['S'].x; tmpy = sty + point['S'].y; }
		else if(dir == 'W') { tmpx = stx + point['W'].x; tmpy = sty + point['W'].y; }

		if(mat[stx][sty] == -1 && (tmpx < 0 || tmpx > maxrow || tmpy < 0 || tmpy > maxcol) ){ return true; }

		if(tmpx < 0 || tmpx > maxrow || tmpy < 0 || tmpy > maxcol)
		{
			return false;
		}

		stx = tmpx, sty = tmpy;
	}
	return true;
}

int main()
{
	char s2[MAX];
	init();
	gets(str);
	sscanf(str, "%d %d", &maxrow, &maxcol);
	memset(mat, 1, sizeof(mat));

	while(gets(str))
	{
		cnt = 0;
		stx = 0, sty = 0, dir = '\0';
		if(sscanf(str, "%d %d %s", &stx, &sty, s2)!=3)
			continue;
		dir = toupper(s2[0]);

		gets(str);
	
		int len = strlen(str); int i; bool flag;
		for(i = 0; i < len; i++)
		{
			flag = visit(str[i]);
			if(flag == false)
				break;
		}

		printf("%d %d %c", stx, sty, dir);
		if(flag == false)
		{
			mat[stx][sty] = -1;
			printf(" LOST");
		}
		printf("\n");
	}
    return 0;
}
