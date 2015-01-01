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
#define MAX 300
typedef pair<int, int>p;

#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

double check(char s)
{
	     if(s == 'W')
		return 1.00;
	else if(s == 'H')
		return 0.50;
	else if(s == 'Q')
		return 0.250;
	else if(s == 'E')
		return 0.1250;
	else if(s == 'S')
		return 0.06250;
	else if(s == 'T')
		return 0.031250;
	else if(s == 'X')
		return 0.015625;
}

char str[MAX];
int main()
{
	while(gets(str))
	{
		if(strcmp(str, "*") == 0)
			break;

		int i, cnt = 0;
		int len = strlen(str);
		double r;
		
		r = 0.0;
		for(i = 0; i < len; i++)
		{
			if(str[i] == '/')
			{
				if(r == 1.000)
					cnt++;
				r = 0.0;
				continue;
			}

			r += check(str[i]);
		}

		printf("%d\n", cnt);
	}
	return 0;
}