#include <stdio.h>
#include <math.h>

int main()
{
    long double r ;
	long double area1;
    long double area2;
    long double area3;

    
    while(scanf("%Lf", &r)!=EOF)
    {
        long double pi = 2.00*acos(0.00) ;

        area1 = pow(r, 2) * (pi/3.00 + 1.00 - sqrt(3.00)) ;
		area2 = pow(r, 2) * (pi - 2.00) - 2.00*area1 ;
		area3 = pow(r, 2) - area1 - area2 ;
        
        printf("%.3Lf %.3Lf %.3Lf\n", area1, area2, area3);
    }
    
    return(0) ;
}