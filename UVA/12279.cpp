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

typedef pair<int, int>p;

#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

int main()
{
	int n, cnt = 1;

	while(scanf("%d", &n)==1)
	{
		if(!n)
			break;

		int cnt0 = 0, cntn0 = 0;
		for(int i = 0; i < n; i++)
		{
			int m;
			scanf("%d", &m);
			if(m == 0)
				cnt0++;
			else
				cntn0++;
		}

		printf("Case %d: %d\n", cnt++, cntn0 - cnt0);
	}
	return 0;
}