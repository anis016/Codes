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

char s[2000];
char temp[2000];

void Tolower()
{
	int len, i;
	len = strlen(s);

	for(i = 0; i < len; i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
			continue;
		else if(s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] - 'A' + 'a';
		}
		else
			continue;
	}
}

int main()
{
//	Fin;

	bool flag;
	char fis, sec;

	while(gets(s))
	{
		Tolower();
		if(strcmp(s, "*") == 0)
			break;

		fis = s[0];
		flag = false;
		char *p = strtok(s, " ");
		while(p)
		{
			strcpy(temp, p);
			sec = temp[0];

			if(sec != fis)
			{
				flag = true;
				break;
			}

			p = strtok(NULL, " ");
		}

		if(flag == true)
			printf("N\n");
		else
			printf("Y\n");
	}
	return 0;
}