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

bool check_in(int m)
{
	int n;
	while( m )
	{
		n = m % 10;
		int s = n & 7;
		if(s == 7)
			return true;
		m = m / 10;
	}
	return false;
}

bool check(int Act)
{
	if( (Act % 7) == 0 || check_in(Act) )
		return true;
	return false;
}

int main()
{
	int m, j, n, k;

	while(scanf("%d %d %d", &n, &m, &k) == 3)
	{
		if(!n && !m && !k)
			break;
		
		int cnt = 0, Act = 0;
		j = 1;
		bool t = true;
		while(1)
		{
			Act++;

			if(j == n)
			{
				j = n;
				t = false;
			}
			else if(j == 1)
			{
				j = 1;
				t = true;
			}

			if(check(Act))
			{
				if(j == m)
					cnt++;
				if(j == m && cnt == k)			
					break;
			}

			if(t == true)
				j++;
			else
				j--;
		}

		printf("%d\n", Act);
	}
	return 0;
}