#include<stdio.h>

main()
{
 long double  i, series;

 while(scanf("%llf", &i)!=EOF)
 {
  if(i<0)
	  break;
  else
  {
   series=((i*i)*(i+1)*(i+1))/4;
   printf("%.0llf\n", series);
  }
 }
 return 0;
}