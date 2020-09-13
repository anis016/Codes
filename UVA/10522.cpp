#include<stdio.h>
#include<math.h>

int main()
{
	long long i;
	long double Ha, Hb, Hc, a, b, c, area,total;

	scanf("%lld", &i);	
	while(1)
    {
             if(i==0)
	         break;
    	 	
	while(scanf("%Lf %Lf %Lf", &Ha, &Hb, &Hc)!=EOF)
	{
	   a=1/Ha;
	   b=1/Hb;
	   c=1/Hc;

	   total=1/( (a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c) );
	  
	   if(total<0 || Ha<=0 || Hb<=0 || Hc<=0)   ////////////////critical thing Ha<=0 || Hb<=0 || Hc<=0
	   {
		   printf("These are invalid inputs!\n");
		     i--; 
		   if(i==0)
	         break;
	   }
	   
	   else 
	   {
		  area=sqrt(total);
		  printf("%.3Lf\n", area);
	   }
		
	}
	
}
	return 0;
}
