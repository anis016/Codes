#include <math.h>
#include <stdio.h>

int main(void)
{
    long double hold, x;

    long j,  length, sum=0, final;

   while(scanf("%Lf", &x), x)
   {
//       hold = log10(x);
	   
//	 length = long(floor(hold)+1);                  //////////find the length of the integer

	 j=long(x);
	 
	 sum=0; 

	 final=j;
	 while(final>=10)                                 /////////adding untill summation is less den 10
		for(sum=final,final=0; sum!=0; sum/=10)
			final+=sum%10;
		
		printf("%ld\n", final);

   }
   return 0;
}
