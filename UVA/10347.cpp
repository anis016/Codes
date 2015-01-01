#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, s, area, final;

	while(scanf("%lf %lf %lf", &a, &b, &c)!=EOF)
	{
		s=(a+b+c)*0.5;
				if(s>a && s>b && s>c)
		{
             final=s*(s-a)*(s-b)*(s-c);

			area=sqrt(final)*(4.0/3.0);
		    printf("%.3lf\n", area);
		}
		else
		printf("-1.000\n");
	}

	return 0;
}
