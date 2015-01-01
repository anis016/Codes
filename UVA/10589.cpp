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
inline bool iseq(double x,double y){if( x <= y )return true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)
//#define MAX 1000001
#define MAX 50

int edge, vertex;
vector<int>V[MAX];

int main()
{
//	Fin;

	long N, aa;
	long i;

	while(scanf("%ld %ld", &N, &aa)==2)
	{
		if(!N)
			break;

		long M = 0;
		double a = aa * 1.0000;	
		for(i = 0; i < N; i++)
		{
			double x, y;
			scanf("%lf %lf", &x, &y);

			double A = sqrt( (x)*(x) + (y)*(y) );
			double B = sqrt( (x-a)*(x-a) + (y)*(y) );
			double C = sqrt( (x-a)*(x-a) + (y-a)*(y-a) );
			double D = sqrt( (x)*(x) + (y-a)*(y-a) );

			if(iseq(A, a) && iseq(B, a) && iseq(C, a) && iseq(D, a) )
				M++;
		}

		printf("%.5lf\n",( (double)M*( (double)(aa*aa)/(double)N ) ) + eps) ;
	}

	return 0;
}