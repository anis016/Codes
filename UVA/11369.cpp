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
#define MAX 200000

long Cost[MAX];

int main()
{
//	Fin;

	long n;

	scanf("%ld", &n);
	while(n--)
	{
		long nn;
		scanf("%ld", &nn);

		for(long i = 0; i < nn; i++)
		{
			long m;
			scanf("%ld", &m);

			Cost[i] = m;
		}

		sort(Cost, Cost + nn);

		long sum = 0, j = 1;
		for(long i = nn; i >= 0; i--)
		{
			if( (j % 3) == 0 )
			{
				sum += Cost[nn - j];
			}
			j++;
		}

		printf("%ld\n", sum);
	}
	return 0;
}
