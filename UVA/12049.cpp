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

int main () 
{
 //   Fin;
	int n, L1, L2;

	scanf("%d", &n);
	while(n--)
	{
		multiset<int>S1, S2;
		scanf("%d %d", &L1, &L2);

		for(int i = 0; i < L1; i++)
		{
			int elem;
			scanf("%d", &elem);
			S1.insert(elem);
		}

		for(int i = 0; i < L2; i++)
		{
			int elem;
			scanf("%d", &elem);
			if(S1.find(elem) == S1.end() )
				S2.insert(elem);
			else
				S1.erase(S1.find(elem));
		}

		printf("%d\n", S1.size() + S2.size() );
	}
    return 0;
}
