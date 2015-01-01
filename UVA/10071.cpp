#include<stdio.h>

main(void)
{
 long int t, v, d;
 while(scanf("%ld %ld", &v, &t)!=EOF)
 {
  if(-100<=v&&v<=100)
  if(0<=t&&t<=200)
  {
   d=2*t*v;
   printf("%ld\n", d);
   }
 }
 return 0;
}