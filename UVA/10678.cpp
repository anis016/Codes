#include<stdio.h>
#include<math.h>

int main()
{

	const double pi = 2*acos(0.000);
	long double area, c, a, b, hold_1, hold_2, hold_3;
	
	long L, D, n, i;

	scanf("%ld", &n);
	for(i=0;i<n;i++)
	{
		scanf("%ld %ld", &D, &L);
			
		a=double(L)/2;
		c=double(D)/2;
		
		hold_1=pow(a,2);
		hold_2=pow(c,2);

		hold_3=hold_1-hold_2;

		b=sqrt(hold_3);
		
		area=pi*a*b;
		
		printf("%.3Lf\n", area);
	}
		
	return 0;

}