#include<stdio.h>
#include<math.h>
#define PI 2*acos(0)

int main()
{
	double t=0.0000, r1,  area_gray;
	long test, i;
	char sp;


	scanf("%ld", &test);
	for(i=0; i<test; i++)
	{
		scanf("%lf", &t);
		 scanf("%c", &sp);
		  if(sp!=' ')
		  {
			  area_gray = (PI*t*t)/8;
			  printf("%.4lf\n", area_gray);
		  }
		  else if(sp==' ')
		  {
			  scanf("%lf", &r1);
			  area_gray= 2*PI*t*r1;
			  printf("%.4lf\n", area_gray);
		  }

	}
	return 0;
}	