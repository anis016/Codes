#include<stdio.h>
#include<math.h>
main(void)
{
 double n,p,k;
 scanf("%lf %lf",&n ,&p);
 k=exp(log(p)/n);
 printf("%.0lf\n",k);
 return 0;
}