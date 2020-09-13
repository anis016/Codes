#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

int main()
{
	double i, j, k, l, m, n;
	double A, B, C, area, S, rad, circum; 

	while((scanf("%lf %lf %lf %lf %lf %lf", &i, &j, &k, &l, &m, &n))!=EOF)
		{
			A=sqrt(pow((i-k), 2) + pow((j-l), 2)); 
			B=sqrt(pow((i-m), 2) + pow((j-n), 2));
			C=sqrt(pow((k-m), 2) + pow((l-n), 2));
			
			S=(A+B+C)/2;							
			area=sqrt(S*(S-A)*(S-B)*(S-C));

			rad=(A*B*C)/(4*area);					
			circum=2*PI*rad;

			printf("%.2lf\n", circum);
		}

	return 0;

}
