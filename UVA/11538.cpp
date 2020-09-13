// m * (m-1) * n + n * (n-1) * m +(n*(n-1)*(2*n+1)/6-(n-1)*n/2)*4+2*n*(n-1)*(m-n+1);

// horizontal queen attack => m*(m-1)*n
// vertical queen attack => n*(n-1)*m
// diagonal queen attack(power of square) => n(n+1)(2n-1)/6 - (n*(n-1)/2)*2 + n*(n-1)*(m-n+1)
// As the problem it is clear that all are 2 ways hence multiply by 2
// n must be smaller then m

#include<stdio.h>
#define swap(x, y) x^=y^=x^=y
typedef unsigned long long  __ull;

int main()
{
	__ull m, n, res;

	while(scanf("%llu %llu", &m, &n)==2)
	{
		if(n > m)
			swap(m, n);

		if(!m && !n)
			break;
		
		res = m*(m-1)*n+n*(n-1)*m+(n*(n-1)*(2*n-1)/6-(n-1)*n/2)*4+2*n*(n-1)*(m-n+1);
		printf("%llu\n", res);
	}
	return 0;
}