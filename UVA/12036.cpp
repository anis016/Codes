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

#define MAX 110
int Row[MAX];
int N;

void read()
{
	int M, i, j;
	for(i = 1; i <= N; i++)
		for(j = 1; j <= N; j++)
		{
			scanf("%d", &M);
			Row[M]++;
		}
		
	return ;
}

int process()
{
	for(int i = 0; i <= 100; i++)
	{	if(Row[i] > N)
			return 1;
	}
	return 0;
}

int main()
{
	int counter = 1, n;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &N);
	
		memset(Row, 0, sizeof(Row));
		read();

		int count = process();	
		if(count == 1)
			printf("Case %d: no\n", counter++);
		else
			printf("Case %d: yes\n", counter++);
	}
    return 0;
}
