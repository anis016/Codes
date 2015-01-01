#include<stdio.h>
#include<math.h>
#define EPSILON pow(10, -9)
#define MAX 1000000

int main()
{
    double hold[MAX+100];
	long power[MAX];

	long  n, i;

	hold[0]=5.0;
	power[0]=1;
	
	for(i=1; i<MAX; i++)
	{
		hold[i]=1/2.0 * hold[i-1];
		power[i]=power[i-1];

		if((long)hold[i] == 0)
            hold[i] = hold[i]*10.0, power[i]++;
	}

	while(scanf("%ld", &n)!=EOF)
	{
		printf("2^-%ld = %.3lfe-%ld\n", n, EPSILON+hold[n-1], power[n-1]);	
	}
	return 0;
}

/*
#include<stdio.h>          //// ACCEPTED
#include<math.h>

int main()
{
	long n;
	long double x, digit;

	while(scanf("%ld", &n)!=EOF)
	{
		 digit = floor(log10(2)*n + 1);
		 x = pow(2, (digit / log10(2) - n)); 
         
		 printf("2^-%ld = %.3Lfe-%.0Lf\n", n, x, digit);
	}
	return 0;
}

  //////////////////  FORMULA //////////////////////

digit = floor(log10(2)*n + 1); 

// find the x 

a = 10^digit / 2^n 
log2(a) = log2(10^digit) - n*log2(2); 
log2(a) = digit*log2(10) - n; 
log2(a) = digit / log10(2) - n; 

then 
x = 2^(digit / log10(2) - n); 
y = digit;

*/