#pragma warning (disable : 4786)
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
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return 
true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

int main()
{
	int test; int t = 1;

	scanf("%d", &test);
	while(test--)
	{
		map<string, int>M;
		map<string, int>::iterator it;

		char str[100];

		int n, i, d, m;
		scanf("%d", &n);
		for(i = 0; i < n; i++)
		{
			scanf("%s %d", str, &m);
			M[str] = m;
		}
		scanf("%d", &d);
		scanf("%s", str);

		it = M.find(str);
		if(it==M.end())
		{
			printf("Case %d: Do your own homework!\n", t++);
			continue;
		}
		
		int k = it->second;
		if(k <= d)
			printf("Case %d: Yesss\n", t++);
		else if(k <= (d + 5) && k > d)
			printf("Case %d: Late\n", t++);
		else
			printf("Case %d: Do your own homework!\n", t++);
	}
	return 0;
}
