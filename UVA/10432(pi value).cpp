#include<stdio.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795029L

int main()
{
	long double area, r, n;

	while(scanf("%llf %llf", &r, &n)!=EOF)
	{
			area=0.5000*r*r*(n)*sin((2.0*PI)/(n));
			printf("%.3llf\n", area);			
	}

	return 0;
}