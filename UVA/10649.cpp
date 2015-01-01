#include<stdio.h>
#include<math.h>

int main()
{
	long double r, a, s, temp;

	while(scanf("%Lf %Lf", &r, &a)==2)
	{
		if(r==0.0 && a==0.0)
			break;

		r=r/2.0;
		if( (a*a) >= (2*r*r) )
		{
			printf("INCORRECT INFORMATION !!!\n");
			continue;
		}

		temp =  sqrt(2 * r * r - a * a);
		s = sqrt(2 * (r * r + a * temp)) - a;

		printf("%.6Lf\n", s);
	}
	return 0;
}