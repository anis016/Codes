#include<stdio.h>
#include<iostream>
#include<math.h>

#define EPS pow(10,-9)
using namespace std;

int main()
{
	char ch1, ch2;
	double e, hold, ans;
	float num1, num2, h;

	while(cin>>ch1)
	{
		hold=e=h=ans=0.000;
		if(ch1=='E')
			break;
		else
		{
			cin>>num1>>ch2>>num2;

			if(ch1=='T' && ch2=='D')
			{
				hold = 5417.7530 * ((1/273.16) - (1/(num2+273.16)));
				e = 6.11 * exp(hold);
				h = 0.5555 * (e-10.00);

				ans = num1 + h;
				printf("T %.1f D %.1f H %.1lf\n", num1, num2, (ans+EPS));
			}
			else if(ch1=='D' && ch2=='T')
			{
				hold = 5417.7530 * ((1/273.16) - (1/(num1+273.16)));
				e = 6.11 * exp(hold);
				h = 0.5555 * (e-10.00);

				ans = num2 + h;

				printf("T %.1f D %.1f H %.1lf\n", num2, num1, (ans+EPS));
			}
			else if(ch1=='H' && ch2=='D')
			{
				hold = 5417.7530 * ((1/273.16) - (1/(num2+273.16)));
				e = 6.11 * exp(hold);
				h = 0.5555 * (e-10.00);

				ans = num1 - h;
				printf("T %.1lf D %.1f H %.1f\n", (ans+EPS), num2, num1);
			}
			else if(ch1=='D' && ch2=='H')
			{
				hold = 5417.7530 * ((1/273.16) - (1/(num1+273.16)));
				e = 6.11 * exp(hold);
				h = 0.5555 * (e-10.00);

				ans = num2 - h;
				printf("T %.1lf D %.1f H %.1f\n", (ans+EPS), num1, num2);
			}
			else if(ch1=='H' && ch2=='T')
			{
				h = num1-num2;
				e = (h/0.5555) + 10.0;
				hold = 5417.7530/( (5417.7530/273.16) - log(e/6.11) );
				
				ans = hold-273.16;
				printf("T %.1f D %.1lf H %.1f\n", num2, (ans+EPS), num1);

			}
			else if(ch1=='T' && ch2=='H')
			{
				h = num2-num1;
				e = (h/0.5555) + 10.0;
				hold = 5417.7530/( (5417.7530/273.16) - log(e/6.11) );
				
				ans = hold-273.16; 
				printf("T %.1f D %.1lf H %.1f\n", num1, (ans+EPS), num2);

			}
		}
	}	
	return 0;
}