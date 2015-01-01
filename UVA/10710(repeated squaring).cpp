#include<stdio.h>
typedef long long LL;

LL rep_square(LL expo, LL mod)
{
	if(expo == 0)
		return 1;

	else if(expo == 1)
		return 2;

	LL temp = rep_square(expo / 2, mod) % mod;
	LL ret = (temp * temp) % mod;

	if(expo % 2 == 1)
		ret = (ret * 2) % mod;

	return ret;
}

LL N;

int main()
{
	LL M, T, MOD;

	while(scanf("%lld", &N)==1)
	{
		if(N < 0)
			break;

		MOD = N;
		M = N - 1;

		T = rep_square(M, MOD);

		if(T != 1)
			printf("%lld is not a Jimmy-number\n", N);
		else
			printf("%lld is a Jimmy-number\n", N);
	}
	return 0;
}