#include<stdio.h>
#include<math.h>
#define pi 3.1415926535897932384626433832795029L

int main()
{
	long  res;
    long n, Case;
	double log2pin, nlogn_loge, by2;

	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld", &n);
		if(n == 1)
		{
			printf("1\n");
			continue;
		}

		log2pin = log10(2.0 * pi * double(n) );
		by2 = log2pin / 2.0;
		nlogn_loge = double(n) * ( log10(double(n) ) - log10(exp(1.0)) );

		res = floor( by2  + ( nlogn_loge ) + 1.0 );
		printf("%ld\n", res);
	}
	return 0;
}