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
	long b, s, cnt = 1;
	
	while(scanf("%ld %ld", &b, &s) == 2)
	{
		if(!b && !s)
			break;

		long age, Min = pinf;
		for(int i = 0; i < b; i++)
		{
			scanf("%ld", &age);
			if(age < Min)
				Min = age;
		}
		age = Min;

		for(int i = 0; i < s; i++)
		{
			long ss;
			scanf("%ld", &ss);
		}

		if(b > s)
			printf("Case %ld: %ld %ld\n", cnt++, b - s, age);
		else
			printf("Case %ld: 0\n", cnt++);
	}	
	return 0;
}