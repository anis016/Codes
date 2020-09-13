#include<stdio.h>
#include<math.h>
typedef long long LL;

LL H( int n )
{
	int n2 = (LL)sqrt( n );
	int i;
	LL res = 0;
	
	for( i = 1; i <= n2; ++i )
		res += n / i;
	
	return res * 2 - n2 * n2;
}


int main()
{
	int n, test;
	
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		printf("%lld\n", H( n ) );
	}
	return 0;
}