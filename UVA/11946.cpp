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

char m[60] = {0};
void init()
{
	m['3'] = 'E'; m['0'] = 'O'; m['1'] = 'I'; m['4'] = 'A'; m['9'] = 'P'; m['8'] = 'B'; m['5'] = 'S'; m['7'] = 'T'; m['2'] = 'Z';
	m['6'] = 'G';
}

int main() 
{
	init();

	int test;
	char ch;
	
	scanf("%d", &test);
	getchar();
	while(test--)
	{
		while(1)
		{
			ch = getchar();

			if(ch == EOF)
				break;
			else if(ch == '\n')
			{
				ch = getchar();
				if(ch == '\n' || ch == EOF)
				{
					printf("\n");
					break;
				}
				else
				{
					printf("\n");
					goto M;
				}
			}
M:
			if(m[ch] != 0)
				printf("%c", m[ch]);
			else
				printf("%c", ch);
		}
		if(test)
			printf("\n");
	}
	return 0;
}
