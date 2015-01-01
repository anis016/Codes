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
#define Pinf (1<<30)
#define Ninf -1*pinf
#define pi (2*acos(0.0))
//typedef long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}

#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)
#define UP 1
#define DOWN 2
#define Und 0

#define MAX 5000
int holder[MAX];

int main () 
{
	int cnt_min, cnt_max, sum_min, sum_max;
	int in, stp, i, same;
	int status, req;
	while(scanf("%d", &in), in)
	{
		int flag = 0;
		holder[0] = in;
		stp = 1; cnt_min = same = req = cnt_max = sum_min = sum_max = 0;
		status = Und;
		while(scanf("%d",  &in), in)
			holder[stp++] = in;

		for(i = 1; i < stp; i++)
		{
			flag = 0;
			if(holder[i] > holder[ i - 1])
			{
				if(status == Und || status == DOWN)
				{
					cnt_max++;
					sum_max += 1;
					flag = 1;
				}
				if(req == 1)
				{					
					if(status == Und)
						sum_max += same;
					else if(status == UP)
						sum_max += same + 1;
					else if(status == DOWN)
						sum_min += same;

					same = 0;
					req = 0;
				}
				else if(flag == 0 && req == 0)
				{
					sum_max += 1;
					req = 0;
				}
				status = UP;
			}
			else if(holder[i] < holder[ i - 1])
			{
				if(status == Und || status == UP)
				{
					cnt_min++;
					sum_min += 1;
					flag = 1;
				}
				if(req == 1)
				{
					if(status == Und)
						sum_min += same;
					else if(status == UP)
						sum_max += same;
					else if(status == DOWN)
						sum_min += same + 1;

					same = 0;
					req = 0;
				}
				else if(flag == 0 && req == 0)
				{
					sum_min += 1;
					req = 0;
				}
				status = DOWN;
			}
			else
			{
				same++;
				req = 1;
			}
		}

		if(status == DOWN && req == 1)
			sum_min += same;
		else if(status == UP && req == 1)
			sum_max += same;

		if(cnt_min == 0 && cnt_max == 0)
			printf("Nr values = %d:  0.000000 0.000000\n", stp );
		else if(cnt_min == 0 && cnt_max != 0)
			printf("Nr values = %d:  %.6lf 0.000000\n", stp, (double)sum_max / (double)cnt_max );
		else if(cnt_min != 0 && cnt_max == 0)
			printf("Nr values = %d:  0.000000 %.6lf\n", stp, (double)sum_min / (double)cnt_min );
		else
			printf("Nr values = %d:  %.6lf %.6lf\n", stp, (double)sum_max / (double)cnt_max, (double)sum_min / (double)cnt_min );
	}
	return 0;
}