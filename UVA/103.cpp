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

#define MAX 30

struct List
{
	int pos, mat[MAX];
}list[MAX];

int k, n;

void read_input()
{
	int node, i, j;
	for(i = 0; i < k; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &node);
			list[i].mat[j] = node;
		}
		list[i].pos = i + 1;
		sort(list[i].mat, list[i].mat + n);
	}
	return ;
}

bool cmp(int x, int y)
{
	int i;
	for(i = 0; i < n; i++)
		if(list[x].mat[i] <= list[y].mat[i])
			return false;
	return true;
}

void Sort()
{
	int i, j;
	for(i = 0; i < k; i++)
		for(j = 0; j < k; j++)
			if(cmp(i, j))
				swap(list[i], list[j]);
	return ;
}

int pred[MAX], length[MAX];
void init()
{
	int i;
	for(i = 0; i <= k; i++)
		length[i] = 1, pred[i] = -1;
	return ;
}

void ConstructLIS()
{
	int i, j;
	for(i = 0; i < k; i++)
	{
		for(j = i + 1; j < k; j++)
		{
			if(cmp(i, j))
				if(length[i] + 1 > length[j])
				{
					length[j] = length[i] + 1;
					pred[j] = i;
				}
		}
	}
	return ;
}

int main () 
{
//    Fin;

	while(scanf("%d %d", &k, &n)==2)
	{
		read_input();
		Sort();
		init();
		ConstructLIS();

		int i;
		int Max = -1; int index = -1;
		for(i = 0; i <=k; i++)
			if(Max < length[i])
			{
				Max = length[i];
				index = i;
			}

		printf("%d\n", Max);
		printf("%d", list[index].pos);
		for(i = pred[index]; i != -1; )
		{
			printf(" %d", list[i].pos);
			i = pred[index = i];
		}
		printf("\n");
	}
    return 0;
}
