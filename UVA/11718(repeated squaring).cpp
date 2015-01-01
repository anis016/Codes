#include<stdio.h>

typedef long long LL;

long mod;
LL rep_sq(LL n, LL p)
{
	if(p == 0) 
		return 1;
	else if(p == 1)
		return n;

	LL tmp = rep_sq(n,p/ 2)%mod;
	LL ret = (tmp*tmp)%mod;
	
	if(p % 2 == 1)
		ret=(ret*n)%mod;

  return ret;
}

int main()
{
	LL n, k,i, sum, num, Case, j, pow;

	scanf("%lld", &Case);

	for(j=1; j<=Case; j++)
	{
		scanf("%lld %lld %lld", &n, &k, &mod);
		

		pow = ( rep_sq(n, k-1) * k ) % mod;

		sum = 0;
		for(i=0; i<n; i++)
		{
			scanf("%lld", &num);
			sum = ( sum + (num * pow) % mod ) % mod;
		}
		printf("Case %lld: %lld\n", j, sum);
	}
	return 0;
}
