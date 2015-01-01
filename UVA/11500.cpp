#include<stdio.h>
#include<math.h>

double EV1,EV2,AT,D;

int main() 
{
	while(scanf("%lf %lf %lf %lf", &EV1, &EV2, &AT, &D)==4 && (EV1+EV2+D+AT) )
	{
		double n1 = ceil( EV1 / D );
		double n2 = ceil( EV2 / D );
		double p = AT / 6.0;
		double q = 1.0 - p;
		double res = 0.00;

		if( p == 0.5 && q == 0.5)
		    res = n1/(n1+n2);
		else
		{
			double A = 1.0 - pow( ( q / p), n1);
			double B = 1.0 - pow( ( q / p), (n1+n2) );

			res = A / B;
		}

		printf("%.1lf\n", res * 100);
	}
	return 0;
}
