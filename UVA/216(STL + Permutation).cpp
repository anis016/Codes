#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 10
#define eps 1e-8

long vertex, edge;

struct List
{
	long x, y;
}list[MAX];

double make_coordinate(long x1,long y1,long x2,long y2)
{
	long xx = (x1 - x2);
	long yy = (y1 - y2);
	
	double out = sqrt((double)( ( xx * xx ) + ( yy * yy ) )) + 16.00;
	return out;
}

char as[] = "**********************************************************";

int main()
{
	long i, test;

	for (test = 1; scanf("%d", &vertex) == 1 && vertex > 0; test++)
	{
		long T[MAX] = {0};
		long temp[MAX];

		for(i = 0; i < vertex; i++)
		{
			long x, y;
			scanf("%d %d", &x, &y);
		
			list[i].x = x;
			list[i].y = y;		
			temp[i] = i;
		}

		double maxi = 9999999999.00;
		do {
			
			double res = 0.00;
			for(i = 0; res < maxi && i < vertex - 1; i++)
			{
				long x1 = list[temp[i]].x; long x2 = list[temp[i+1]].x;
				long y1 = list[temp[i]].y; long y2 = list[temp[i+1]].y;

				res += make_coordinate(x1, y1, x2, y2);
			}

			if(res < maxi)
			{
				for(i = 0; i < vertex; i++)
					T[i] = temp[i];

				maxi = res;
			}
		}while(next_permutation(temp, temp + vertex));

		printf("%s\n", as);
		printf("Network #%d\n", test);
	
		double sum = 0.00;
		for(i = 0; i < vertex - 1; i++)
		{
			long x1 = list[T[i]].x; long x2 = list[T[i+1]].x;
			long y1 = list[T[i]].y; long y2 = list[T[i+1]].y;

			double res = make_coordinate(x1, y1, x2, y2);
			sum += res;

			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x1, y1, x2, y2, res);
		}
		printf("Number of feet of cable required is %.2lf.\n", sum);
	}

	return 0;
}