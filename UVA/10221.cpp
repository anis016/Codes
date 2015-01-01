#include<stdio.h>
#include<math.h>
#include<string.h>
#define PI 2*acos(0.000000)

int main()
{
	char aa[100];
	long double arc_dist, chord_dist, rad, d, hold_deg, radian_1, hold, rad1, degree, dg;

	while(scanf("%Lf %Lf %s", &rad1, &d, aa)!=EOF)
	{
		rad = rad1+6440;

		if(d>180.00000)
			d = 360.00000-d;

		if(strcmp(aa,"deg")==0)
			hold_deg = d;
		else if(strcmp(aa,"min")==0)
			hold_deg = d/60.000000;
		
		radian_1 = (hold_deg * PI)/180;

		arc_dist = rad*radian_1;

		hold = hold_deg/2;
		degree = (hold /180) * PI;
	    chord_dist = 2 * rad * sin(degree);

		printf("%Lf %Lf\n", arc_dist, chord_dist);

	}

	return 0;
}