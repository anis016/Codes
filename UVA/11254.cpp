#include<stdio.h>
#include<math.h>

typedef long Long;
#define swap(xxx, yyy) xxx^=yyy^=xxx^=yyy
#define MAX 10

Long odd[MAX];

long find_odd_divisors(Long N)
{
	Long i, j, ho;
	for(i=1, j=0; i<=sqrt(N); i++)
	{
		if( (N%i)==0)
		{
			ho = N / i;
			if(ho%2==1)
			{
				odd[j++] = ho;
			}
			if(i%2==1)
			{
				odd[j++] = i;
			}
		}
	}
	return j;
}

long from[MAX];

int main()
{
	Long A, B, u, v, n, m, N, len, i, diff, k, max;

	while(scanf("%lld", &N)==1)
	{
		if(N<0)
			break;

		k = 0;
		max = 0;
		
		len = find_odd_divisors(N);
		if(len == 1)
		{
			from[0] = N;
			from[1] = N;
		}
		else
		{
			for(i=0; i<len; i++)
			{
				A = odd[i];
				B = (2*N) / odd[i];

				if(B<A)
					swap(A, B);

				v = (B + A);
				u = (B - A);

				n = (v - 1) / 2;
				m = (u - 1) / 2;

				diff = m - n;
				if(diff<0)
					diff *= -1;

				if(diff > max)
				{
					max = diff;
					from[0] = m+1;
					from[1] = n;
				}
			}
		}

		printf("%lld = %lld + ... + %lld\n", N, from[0], from[1]);
	}
	return 0;
}