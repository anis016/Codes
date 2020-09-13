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
#define MAX 10000
typedef pair<int, int>p;

#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

char str[MAX+MAX+MAX+MAX];
int A[20];
int main()
{
	int n, m;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &m);
		int k = 0;
		for(int i = 1; i <= m; i++)
		{
			int j = i;
			while(j)
			{
				str[k++] = (j % 10) + '0';
				j = j / 10;
			}
		}

		for(int i = 0; i < k; i++)
		{
			A[str[i] - '0']++;
		}

		printf("%d", A[0]);
		for(int i = 1; i < 10; i++)
			printf(" %d", A[i]);
		printf("\n");

		memset(A, 0, sizeof(A));
	}
	return 0;
}