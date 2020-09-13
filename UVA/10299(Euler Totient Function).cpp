// 	phi(p^n) = p^(n-1) (p - 1), p prime
//  phi(a b) = phi(a) phi(b), if gcd(a,b) == 1
//  Euler Totient

#include<stdio.h>
#include<math.h>
#define MAX 31630

long a[MAX + 100];
long is_prime[MAX + 100];

void init_prime()
{
	long i, j, k, t;
	long M = (long)sqrt(MAX);

	for(i = 3; i <= M; i +=2)
		if(a[i] == 0)
			for(j = i * i; j <= MAX; j += i + i)
				a[j] = 1;

	is_prime[0] = 2;
	for(k = 3, t = 1; k <= MAX; k += 2)
	{
		if(a[k] == 0)
			is_prime[t++] = k;
	}
	return ;
}

long find_euler_totient(long N)
{
	long i;
	long M = (long)sqrt(N);
	long P = 0;
	long phi = N;
	i = 0;
	while(is_prime[i] <= M)
	{
		if(N % is_prime[i] == 0)
		{
			N = N / is_prime[i];
			P++;
		}
		else
		{
			long base = 0;
			if(P != 0)
			{
				long sum = 0;
				base = is_prime[i];

				phi = phi / is_prime[i] ;
				phi = phi * (is_prime[i] - 1);
			}
			i++;
			P = 0;
		}
	}

	if ( N > 1 )
		phi /= N , phi *= (N - 1) ;

	return phi;
}

int main()
{
	long N;

	init_prime();

	while(scanf("%ld", &N), N)
	{
		if(N == 1)
		{
			printf("0\n");
			continue;
		}
		long totient = find_euler_totient(N);

		printf("%ld\n", totient);
	}
	return 0;
}
