#include<stdio.h>
typedef long tall;

tall X, Y;

tall extended_gcd(tall a, tall b)
{
   //ax + yb = d , d = gcd of a,b
   
	tall x = 0;    
	tall lastx = 1;

    tall y = 1;    
	tall lasty = 0;
	
	tall temp = 0;
	tall quotient = 0;
	
    while (b != 0)
	{
        temp = b;
        quotient = a / b;
        b = a % b;
        a = temp;
        
        temp = x;
        x = lastx-quotient*x;
        lastx = temp;
        
        temp = y;
        y = lasty-quotient*y;
        lasty = temp;
	}
	X = lastx;	
	Y = lasty;
	
	return a;	//gcd
}

int main()
{
	tall a, b, d;

	while(scanf("%lld %lld", &a, &b)==2)
	{
		d=extended_gcd(a, b);
		printf("%lld %lld %lld\n",X, Y, d);
	}
	return 0;
}