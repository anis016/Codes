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
//typedef long long long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

#define MAX 100
char prev[MAX][MAX];

int maxrow, maxcol;
int x, y;

typedef pair<int, int>ii;
map<char, ii>M;

int possible(char ch)
{
	int xx, yy;
	
	xx = M[ch].first;
	yy = M[ch].second;

	if(xx < 0 || yy <0 || xx > maxrow || yy > maxcol)
		return 0;
	
	if(prev[xx][yy] == 'X')
		return 0;
	else if(prev[xx][yy] == '0' || prev[xx][yy] == '2')
		return 1;
	return 0;
}

int R[] = {-1, 0, +1, 0};
int C[] = {0, +1, 0, -1};

void update(int row, int col)
{
	int k, xx, yy;
		
	for(k = 0; k < 4; k++)
	{
		xx = R[k] + row;
		yy = C[k] + col;
	
		if(xx < 0 || yy <0 || xx > maxrow || yy > maxcol)
			continue ;

	    if(prev[xx][yy] == 'X')
			prev[xx][yy] = '1';
	    else if(prev[xx][yy] == '0')
		    prev[xx][yy] = '2';
	}
}

bool next_pos(char ch)
{
	int xx, yy;

	xx = M[ch].first;
	yy = M[ch].second;
	if(prev[xx][yy] == '0' || prev[xx][yy] == '2')
	{
		prev[xx][yy] = '.';
		x = xx; y = yy;
		return true;
	}
	return false;
}

int counter = 0;
void simulate()
{
	int k;
	int newx, newy;

	if(prev[x][y] == 'X')
		prev[x][y] = '0' ;

	prev[x][y] = '.'; update(x, y);
	for( ; ; )
	{
		for(k = 0; k < 4;k++)
		{
			newx = R[k] + x;
			newy = C[k] + y;

			if(k == 0)
				M['N'] = ii(newx, newy);
			else if(k == 1)
				M['E'] = ii(newx, newy);
			else if(k == 2)
				M['S'] = ii(newx, newy);
			else if(k == 3)
				M['W'] = ii(newx, newy);
		}

		char ne;
		int fn = 0, fe = 0, fs = 0, fw = 0;
		for(k = 0; k < 4; k++)
		{
			if(k == 0){
				fn = possible('N');
				if(fn == 1)
				{
					ne = 'N';
					break;
				}
			}
			if(k == 1){
				fe = possible('E');
				if(fe == 1)
				{
					ne = 'E';
					break;
				}
			}
			if(k == 2){
				fs = possible('S');
				if(fs == 1)
				{
					ne = 'S';
					break;
				}
			}
			if(k == 3){
				fw = possible('W');
				if(fw == 1)
				{
					ne = 'W';
					break;
				}
			}
		}
		if((fn + fe + fs + fw) == 0)
				return ;

		bool f = next_pos(ne);
		update(x, y);
		counter++;
	}
}

void print()
{
	int i, j;

	printf("\n");
	
	for(i = 0; i < maxcol; i++)
		if(i == maxcol - 1)
			printf("|---|");
		else
			printf("|---");
	printf("\n");
	for(i = 0; i < maxrow; i++)
	{
		for(j = 0; j < maxcol; j++)
		{
			if(prev[i][j] == '.' || prev[i][j] == '2')
			{
				if(j == maxcol - 1)
					printf("| 0 |");
				else
					printf("| 0 ");
			}
			else if(prev[i][j] == '1')
			{
				if(j == maxcol - 1)
					printf("| X |");
				else
					printf("| X ");
			}
			else
			{
				if(j == maxcol - 1)
					printf("| ? |");
				else
					printf("| ? ");
			}
		}
		printf("\n");
		for(j = 0; j < maxcol; j++)
		if(j == maxcol - 1)
			printf("|---|");
		else
			printf("|---");
		printf("\n");
	}

	printf("\n");
	printf("NUMBER OF MOVEMENTS: %d\n", counter);
}

int main()
{
//	Fin;
//	Fout;
	
	while(scanf("%d %d", &maxrow, &maxcol)==2)
	{
		if(maxrow == 0 && maxcol == 0)
			break;

		scanf("%d %d", &x, &y);
		x--;
		y--;

		int i, j;
		char sp;
		for(i = 0; i < maxrow; i++)
		{
			getchar();
			for(j = 0; j < maxcol; j++)
				if(j == 0)
					scanf("%c", &prev[i][j]);
			    else
					scanf("%c%c", &sp, &prev[i][j]);
		}
		counter = 0;
		simulate();
		print();
	}
	return 0;
}
