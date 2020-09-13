#include<stdio.h>
#include<math.h>

int main()
{
	long n, ans;
	long count=1;

	while(scanf("%ld", &n) && n>=0)
	{
		ans=ceil( log(n)/log(2.0) );
		printf("Case %ld: %ld\n", count++, ans);
	}
	return 0;
}