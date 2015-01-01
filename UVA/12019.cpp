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

struct Date
{
	int month;
	int day;
	int dur;
}date[13];

void check(int d)
{
	if(d == 1)
		printf("Saturday\n");
	else if(d == 2)
		printf("Sunday\n");
	else if(d == 3)
		printf("Monday\n");
	else if(d == 4)
		printf("Tuesday\n");
	else if(d == 5)
		printf("Wednesday\n");
	else if(d == 6)
		printf("Thursday\n");
	else if(d == 7)
		printf("Friday\n");

	return ;
}

int main()
{
//	Fin;

	date[1].month = 1; date[2].month = 2; date[3].month = 3; date[4].month = 4; date[5].month = 5; date[6].month = 6; date[7].month = 7; date[8].month = 8; date[9].month = 9; date[10].month = 10; date[11].month = 11; date[12].month = 12;
	date[1].day   = 1; date[2].day   = 4; date[3].day   = 4; date[4].day = 7; date[5].day = 2; date[6].day = 5; date[7].day = 7; date[8].day = 3; date[9].day = 6; date[10].day =  1; date[11].day =  4; date[12].day =  6;
	date[1].dur = 31; date[2].dur = 28; date[3].dur = 31; date[4].dur = 30; date[5].dur = 31; date[6].dur = 30; date[7].dur = 31; date[8].dur = 31; date[9].dur = 30; date[10].dur = 31; date[11].dur = 30; date[12].dur = 31;

	int mon, da, n;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &mon, &da);
	
		int startM = date[mon].month;
		int startD = date[mon].day;
		int startI = date[mon].dur;

		int j = startD;
		for(int i = 1; i <= startI; i++)
		{
			if(da == i)
				break;

			if( (j % 7) == 0)
			{
				j = 1;
				continue;
			}
			j++;
		}

		check(j);
	}
    return 0;
}
