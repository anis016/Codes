// find such that 1<=i<=N ( (gcd(i, N) != 1) && (gcd(i, N) != i) )
// Euler Totient

#include<stdio.h>
#include<math.h>
#define MAX 46350

long hold[MAX + 100];
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

int Prime(long n)
{
	long i, m;

	if(n==1 || n==0)
		return 0;

	m = (long)sqrt(n); 
	
	for(i=2;i<=m;i++)
		if(n%i == 0)
			return 0;
	return 1;
}


long find_euler_totient(long &expo, long N)
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
				sum += P + 1;

				expo *= sum;
			}
			i++;
			P = 0;
		}
	}

	if ( N > 1 ) 
	{
      phi /= N , phi *= (N - 1) ;
	  expo *= 2;
	}
	return phi;
}

int main()
{
	long N;

	init_prime();

	while(scanf("%ld", &N)==1)
	{
		if(Prime(N) == 1)
		{
			printf("0\n");
			continue;
		}

		long expo = 1;
		long totient = find_euler_totient(expo, N);
		long result = N - totient - expo + 1;

		printf("%ld\n", result);
	}
	return 0;
}
