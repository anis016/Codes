#include<stdio.h>
#include<math.h>

#define PI 3.1415926535897932384626433832795

double a,b,t,res,s,tt,p;

int main()
{
	int cas = 1;

	while( scanf("%lf : %lf",&a,&b)!=EOF )
	{
		s = sqrt(a*a+b*b);
		t= a/s;
		t = asin(t);
		t = ((t/PI) * 180);
		tt = 180-t-90;
		tt = tt*2.0;
		tt = ( (tt/180.0) * PI);

		s = (s*tt+a+a);
		res = 400.0/s;
		printf("Case %d: %.10lf %.10lf\n",cas++,(a*res),(res*b));
	}
	return 0;
}


