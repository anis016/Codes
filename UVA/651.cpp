#include<stdio.h>
#include<math.h>

#define max 100000
#define EPSILON pow(10, -9)

int main()
{
	long n, m;
	double hv[max+10];
	
	hv[0]=0.000;

	for(n=1; n<max; n++)
		hv[n]=((0.500)/(double)n) + hv[n-1];

	printf("# Cards Overhang\n");

	while(scanf("%ld", &m)!=EOF)
		printf("%5ld%10.3lf\n", m, EPSILON+hv[m]);

	return 0;
}