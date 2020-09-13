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
#define MAX 100

int main()
{
//	Fin;
	long long i, n, nn;

	while(scanf("%lld",&n), n)
	{
		nn = n;

		string aa, str;
		i = 0;
		while(n)
		{
			str.push_back( (n % 2) + '0' );
			n = n / 2;
		}
	
		long long flag = 0, len = str.length();
		for(i = 0; i < len; i++)
		{
			if(str.at(i) == '1' && flag == 0)
			{
				aa.push_back(str[i]);
				flag = 1;
				continue;
			}
			else if(str[i] == '1' && flag == 1)
			{
				flag = 0;
			}
			aa.push_back('0');
		}

		long long base = 1, a = 0; 
		for(i = 0; i < aa.length(); i++)
		{
			a += (aa.at(i) - '0') * base;
			base *= 2;
		}

		printf("%lld %lld\n", a, nn - a);
	}
	return 0;
}
