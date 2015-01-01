#include<stdio.h>
#include<math.h>

#define PI 2*acos(0)

int main()
{
	long double area_poly, area, s, n, hold, inrad, outrad, area_circle_big, area_circle_small, spec, offi;
	long count=1;

	while(scanf("%Lf %Lf", &n, &area_poly)!=EOF)
	{
		if(n<3.000000)
			break;
		else
		{
		    area = area_poly;
		    hold = (area_poly * 4* tan(PI/n))/n;
		    s = sqrt(hold);

		    inrad = s/(2*tan(PI/n));
		    area_circle_small= PI*inrad*inrad;
		    offi = area - area_circle_small;

		    outrad =  s/(2*sin(PI/n));
		    area_circle_big= PI*outrad*outrad;
		    spec = area_circle_big - area;

		  printf("Case %ld: %.5Lf %.5Lf\n", count++, spec, offi);
		}
	}

	return 0;
}