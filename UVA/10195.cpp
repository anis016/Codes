#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, s=0, radius=0, area=0, hold=0;

	while(scanf("%lf %lf %lf", &a, &b, &c)!=EOF)
	{
		if(a==0 || b==0 || c==0)
			printf("The radius of the round table is: 0.000\n");
		else
		{	s = .500*(a+b+c);

		    hold= s*(s-a)*(s-b)*(s-c);
		
		    area=sqrt(hold);

		    radius=area/s;

		    printf("The radius of the round table is: %.3lf\n", radius);
		}
		
	}
	return 0;
}