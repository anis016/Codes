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

char s[20];

bool check()
{
	int i;
	int len = strlen(s);
	for(i = 0; i < len; i++)
		if(s[i] != ' ')
			return false;
	return true;
}

int main()
{
	int n = 1;

	while(gets(s))
	{
		if(check())
			continue;
		if(strcmp(s, "") == 0)
			continue;
		else if(strcmp(s, " ") == 0)
			continue;
		else if(strlen(s) == 0)
			continue;
		else if(strcmp(s, "#") == 0)
			break;

		if(strcmp(s, "HELLO") == 0)
		{
			printf("Case %d: ENGLISH\n", n++);
			continue;
		}

		else if(strcmp(s, "HOLA") == 0)
		{
			printf("Case %d: SPANISH\n", n++);
			continue;
		}

		else if(strcmp(s, "HALLO") == 0)
		{
			printf("Case %d: GERMAN\n", n++);
			continue;
		}

		else if(strcmp(s, "BONJOUR") == 0)
		{
			printf("Case %d: FRENCH\n", n++);
			continue;
		}

		else if(strcmp(s, "CIAO") == 0)
		{
			printf("Case %d: ITALIAN\n", n++);
			continue;
		}

		else if(strcmp(s, "ZDRAVSTVUJTE") == 0)
		{
			printf("Case %d: RUSSIAN\n", n++);
			continue;
		}

		else
		{
			printf("Case %d: UNKNOWN\n", n++);
			continue;
		}
		
	}
	return 0;
}