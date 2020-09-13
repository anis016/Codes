#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)

int main()
{
	double a, b, c, p, S, R, r, Red, Blue, Yellow;

	while(scanf("%lf %lf %lf", &a, &b, &c)==3)
	{
		p = (a+b+c)/2.0;
		S = sqrt(p*(p-a)*(p-b)*(p-c));
		R = (a*b*c)/(4.0*S);
		r = S/p;

		Red = (PI*r*r);
		Blue = S-Red;
		Yellow = (PI*R*R)-S;

		printf("%.4lf %.4lf %.4lf\n", Yellow, Blue, Red);
	}
	return 0;
}