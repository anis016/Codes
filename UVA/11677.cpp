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

int main()
{
//	Fin;

	int fHour,fMinute,sHour,sMinute, spendMinute;

	while(scanf("%d %d %d %d",&fHour,&fMinute,&sHour,&sMinute)==4)
	{
		spendMinute = 0;
		if(!fHour&&!fMinute&&!sHour&&!sMinute)
			break;
		else
		{
			if(fMinute > sMinute)
			{
				spendMinute = (60 - fMinute) + sMinute;
				if(fHour > sHour)
				{
					spendMinute += ( ( (sHour + 24) - fHour ) - 1 ) * 60;
					printf("%d\n", spendMinute);
				}
				else if(fHour < sHour)
				{
					spendMinute += ( (sHour - fHour) - 1 ) * 60;
					printf("%d\n", spendMinute);
				}
				else
				{
					spendMinute += ( ( (sHour + 24) - fHour) - 1 ) * 60;
					printf("%d\n", spendMinute);
				}
			}
			else if(fMinute < sMinute)
			{
				spendMinute = (60 - fMinute) + sMinute;
				if(fHour > sHour)
				{
					spendMinute += ( ( ( (sHour + 24) - fHour ) - 1 ) * 60 );
					printf("%d\n", spendMinute);
				}
				else if(fHour < sHour)
				{
					spendMinute += ( (sHour - fHour) - 1 ) * 60;
					printf("%d\n", spendMinute);
				}
				else
				{
					spendMinute = sMinute - fMinute;
					printf("%d\n", spendMinute);
				}
			}
			else
			{
				if(fHour > sHour)
				{
					spendMinute = ( ( (sHour + 24) - fHour ) * 60 );
					printf("%d\n", spendMinute);
				}
				else if(fHour < sHour)
				{
					spendMinute = (sHour - fHour) * 60;
					printf("%d\n", spendMinute);
				}
				else
				{
					printf("%d\n", spendMinute);
				}
			}
		}
	}
	return 0;
}
