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
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

#define MAX 100

int n, m;

int main()
{
//	Fin;

	int i, j;

	while(scanf("%d %d", &n, &m) == 2)
	{
		string final[10000], temp = "";

		cin >> final[0];
		
		for(i = 1; i < n; i++)
		{
			cin >> temp;
			int cnt = 0;
			for(j = 0; j < m; j++)
			{
				if(final[0][j] != temp[j])
					cnt++;
			}

			final[cnt] = temp;
		}

		for(i = 0; i < n; i++)
			cout << final[i]<<endl;
	}
	return 0;
}
