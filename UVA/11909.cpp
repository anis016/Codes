#include<stdio.h>
#include<math.h>

#define eps 1e-8
#define pi (2*acos(0.0))

int main () 
{
	int l, w , h, theta;
	double v_left;

	while(scanf("%d %d %d %d", &l, &w, &h, &theta) == 4)
	{
		double ll = l * tan( theta / 180.0 * pi);
		if(ll - h > eps)
		{
			int left_theta = 90 - theta;
			double eh =  h * tan(left_theta / 180.0 * pi);
			double el = l - eh;
			v_left = (0.5 * eh * h * w) + (el * h * w);
		}
		else
			v_left = 0.50 * l * ll * w;
	
		double v_total = l * w * h;
		printf("%.3lf mL\n", v_total-v_left);
	}
    return 0;
}
