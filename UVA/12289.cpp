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
	char s[100];
	int n;

	gets(s);
	sscanf(s, "%d", &n);
	while(n--)
	{
		gets(s);
		if(strlen(s) == 5)
		{
			printf("3\n");
			continue;
		}
		else
		{
			if( (s[0] == 'o' && s[1] == 'n' && s[2] == 'e' ) || (s[0] == 'o' && s[1] == 'n') || (s[0] == 'o' && s[2] == 'e') || (s[1] == 'n' && s[2] == 'e') )
			{
				printf("1\n");
				continue;
			}
			else
				printf("2\n");
		}
	}
	return 0;
}