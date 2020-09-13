#include<stdio.h>
typedef long long tall;

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
	tall Case, t, m, n, d;
	scanf("%lld", &Case);
	for(t=1; t<=Case; t++)
	{
		scanf("%lld %lld", &m, &n);
		d = extended_gcd(m, n);
		printf("Case %lld: %lld\n", t, (m/d) + (n/d));
	}
	return 0;
}