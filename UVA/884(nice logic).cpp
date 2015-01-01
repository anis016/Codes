#include<stdio.h>
#include<math.h>

#define MAX 1000000

long count[MAX];
long temp[MAX];

long check_prime(long n)
{
	long i;

	if(n==1)
		return 0;
	if(n==2)
		return 1;
	if( (n%2)==0 )
		return 0;

	for(i=3; i*i<=n; i+=2)
		if( (n%i)==0 )
			return 0;

		return 1;
}

void init(void )
{
	long i, j, M, hold;

	hold = 0;
	temp[2] = count[2] = 1;
	for(i=3; i<=MAX; i++)
	{
		M = sqrt(i);

		if(check_prime(i) == 1)
			temp[i] = 1;
		else
		{
			for(j=2; j<=M; j++)
			{
				if( (i%j) == 0)
				{
					hold = j;
					break;
				}
			}
			temp[i] = temp[hold] + temp[i/hold];
		}
		count[i] = count[i-1] + temp[i];
	}

	return ;
}

int main()
{
	long n;

	init();
	while(scanf("%ld", &n)==1)
		printf("%ld\n", count[n]);

	return 0;
}

/*
#include<stdio.h>
#include<math.h>
#define MAX 1000000

long a[MAX+9];
long prime[MAX+10];
long count[MAX+MAX];

void init()
{
	long i,j,k,M,t;
	
	M=sqrt(MAX);
	
	for(i=3;i<=M;i+=2)
		if(a[i]==0)
			for(j=i*i;j<=MAX;j=j+i+i)
				a[j]=1;

	
	prime[0]=2;
	for(k=3, t=1;k<=MAX;k=k+2)
		if(a[k]==0)
		{
			prime[t]=k;
			t++;
		}
	return ;
}

long check_prime(long n)
{
	long i;

	if(n==1)
		return 0;
	if(n==2)
		return 1;
	if( (n%2)==0 )
		return 0;

	for(i=3; i*i<=n; i+=2)
		if( (n%i)==0 )
			return 0;

		return 1;
}

long find_factor(long n)
{
	long sum = 0;
	long i, j;

	if(check_prime(n) == 1)
		return 1;

	i=0;
	while(prime[i] <= n)
	{
		if(n % prime[i] == 0)
		{
			n = n / prime[i];
			sum++;
		}
		else
			i++;
	}

	return sum;
}

int main()
{
	long i, j, k;

	init();
	
	count[2] = 1;
	count[3] = 2;
	for(i=4; i<=1000000; i++)
	{
		k = find_factor(i);
		count[i] = count[i-1] + k ;
	}

	while(scanf("%ld", &j)==1)
		printf("%ld\n", count[j]);

	return 0;
}
*/
  
