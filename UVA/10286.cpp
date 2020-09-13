#include<stdio.h>

int main()
{

	long double in, ans;
	
	while(scanf("%Lf", &in)!=EOF)
	{
       
        // easy refer to acm note-book
	// do not calculate directly , use pc calculator to find sin(108)/sin(63)
	// sin(108)/sin(63) = 1.0673956817111818692592637626711

	 ans = 1.0673956817111818692592637626711 * in;

     printf("%.10Lf\n", ans);
	}

   return 0;
}

