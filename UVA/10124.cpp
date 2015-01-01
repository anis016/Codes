#include<stdio.h>
#include<math.h>

int main()
{
	double D; // - the distance between stations, in metres
	double M; // - the maximum allowable speed of the train, in metres/sec
	double A; // - the maximum absolute acceleration of the train, in metres/sec2
	double J;	// - the maximum absolute jerk, in metres/sec3

	long double jtimeaccellimit, jtimespeedlimit, jtimedistlimit, jtime, atime, a, b, c, r, dist, out_put;

   while(scanf("%lf %lf %lf %lf", &D, &M, &A, &J)!=EOF)
   {

	jtimeaccellimit = A/J;
	jtimespeedlimit = sqrt(M/J);
    jtimedistlimit = exp(log(D/2/J)/3);
	jtime = jtimeaccellimit;

   if(jtimespeedlimit < jtime)
      jtime = jtimespeedlimit;

   if(jtimedistlimit < jtime)
      jtime = jtimedistlimit;

   atime = (M - J*pow(jtime,2))/A;

   a = 0.5*A;
   b = A*jtime + 0.5*J*pow(jtime,2);
   c = (J * pow(jtime,3)) - (D/2);
   r = ((-b + sqrt(b*b - 4*a*c))/2)/a;

   if(r < atime)
       atime = r;

   dist = (J * pow(jtime,3)) + (0.5*J*pow(jtime,2)*atime) + (0.5*A * pow(atime,2)) + (A * atime*jtime);
   out_put = (4*jtime+2*atime+2*(D/2-dist)/M);

   printf("%.1Lf\n", out_put);
  }

   return 0;
}