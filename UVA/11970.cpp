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

int main()
{
//	Fin;

	long n, cnt = 1, mm;
	scanf("%ld", &n);
	while(n--)
	{
		scanf("%ld", &mm);
		long srt = (long)sqrt((double)mm);
		
		printf("Case %d:", cnt++);
		for(long i = srt; i >= 1; i--)
		{
		    long sqr = i * i;
			long sub = mm - sqr;

			if(sub == 0)
				continue;

			if( (sub % i) == 0)
				printf(" %d", sub);
		}
		printf("\n");
	}

	return 0;
}
