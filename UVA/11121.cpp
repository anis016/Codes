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
#define MAX 1000000

char Cost[MAX];
int main()
{
//	Fin;

	long n, counter = 1;

	scanf("%ld", &n);
	while(n--)
	{
		long nn;
		scanf("%ld", &nn);

		printf("Case #%d: ", counter++);
		if(nn == 0)
		{
			printf("0\n");
			continue;
		}

		long i = 0;
		while(nn)
		{
			long rem = nn % -2;
			nn = nn / -2;

			if(rem < 0)
			{
				rem *= -1;
				nn++;
			}

			Cost[i++] = rem + '0';
		}

		int flag = 0;
		for(int j = i - 1; j >= 0; j--)
		{
			if(Cost[j] == '0' && flag == 0)
				continue;
			else
			{
				printf("%c",Cost[j]);
				flag = 1;
			}
		}
		printf("\n");
	}
	return 0;
}
