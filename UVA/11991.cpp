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

#define MAX 1000005

int main()
{
//	Fin;

	int n, m;

	while(scanf("%d %d", &n, &m)==2)
	{
		int x;
		vector< vector<int> >V(MAX);

		int i, j, cnt = 1;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &x);
		
			V[x].push_back(cnt);
			cnt++;
		}

		for(j = 0; j < m; j++)
		{
			int ocr, num;
			scanf("%d %d", &ocr, &num);

			if(V[num].size() < ocr)
			{
				printf("0\n");
				continue;
			}
			int t = ocr - 1;
			printf("%d\n", V[num][t]);
		}
	
	}
	return 0;
}
