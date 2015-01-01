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

#define MAX 610
char s[MAX];

int main()
{
//	Fin;
	int n, m;
	bool blank = false;

	gets(s);
	sscanf(s, "%d", &n);
	for(int yy = 1; yy <= n; yy++)
	{
		gets(s);
		sscanf(s, "%d", &m);
		if( blank ) 
			printf ("\n"); 

		blank = true;
		
		printf("Case %d:\n", yy);
		while(m--)
		{
			gets(s);
			int len, i, j;

			len = strlen(s);
			j = 0;
			for(i = 0; i < len; i++)
			{
				if(s[i] != ' ')
				{
					printf("%c", s[i]);
					j = 0;
				}

				else if(s[i] == ' ' && j == 0)
				{
					printf("%c", s[i]);
					j = 1;
				}
			}
			printf("\n");
		}
	}

    return 0;
}
