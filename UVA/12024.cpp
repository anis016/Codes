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

#define MAX 50
long A[MAX];

long fact(long n)
{
	long res = 1;
	for(int i = 1; i <= n; i++)
		res *= i;
	return res;
}

void init()
{
	int i;
	for(i = 1; i <= 12; i++)
	{
		A[i] = fact(i);
	}
	return ;
}

int main()
{
	int n;

	init();

	scanf("%d", &n);
	while(n--)
	{
		long num;
		scanf("%ld", &num);

		double sum = 1.00;
		for(int i = 1; i <= num; i++)
		{
			if( (i % 2) == 1)
				sum = sum - ( 1.00 / (double)A[i] );
			else
				sum = sum + ( 1.00 / (double)A[i] );
		}

		printf("%0.0lf/%ld\n", (sum * (double) A[num]), A[num]);
	}
    return 0;
}

/*
long A[] = {1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
long B[] = {0,1,2,9,44,265,1854,14833,133496,1334961,14684570,176214841};
int main()
{
	int n, num;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &num);
		printf("%d/%d\n", B[num-1], A[num-1]);
	}
	return 0;
}
*/