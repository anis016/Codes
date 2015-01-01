#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define MAX 32768

long a[MAX+MAX];
long is_prime[MAX+MAX];
long fact[MAX+MAX];
	
long i,j,k,M,t;

void init()
{
	M=sqrt(MAX);
	
	for(i=3;i<=M;i+=2)
		if(a[i]==0)
			for(j=i*i;j<=MAX;j=j+i+i)
				a[j]=1;

	for(k=3, t=1;k<=MAX;k=k+2)
		if(a[k]==0)
		{
			is_prime[t]=k;
			t++;
		}
	is_prime[0]=2;
}

int check_prime(long n)
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

long res;
long power(long base, long expo)
{
	long i;

	for(i=1; i<=expo; i++)
		res=res*base;

	return res;
}

int main()
{
	long in, x, hold, g, hv, j, max, xx, tt, MM, dd;
	
	long prime, base, expo;

	init();

	while(cin>>base)
	{
		if(base==0)
			break;

		res=1;
		
		cin>>expo;
		prime=power(base, expo);
		
		while(getchar() != '\n')
		{
			cin>>base>>expo;
			prime=power(base, expo);
		}

		res=1;	
		in=prime-1;	

		if(check_prime(in)==1)
		{
			printf("%ld 1\n", in);
			continue;
		}

		dd=x=hold=g=hv=xx=tt=0;

		//MM=sqrt(in);
		MM=in/2;
		max=0;
		for(x=0, g=0; is_prime[x]<=MM; x++)
		{
			while(in%is_prime[x]==0)
			{
				hv=in/is_prime[x];
				if(hold==0)
				{
					fact[is_prime[x]]++;
					if(is_prime[x]>max)
						max=is_prime[x];
				}
				in=hv;
			}
		}

		j=0;
		while(1)
		{
			if(fact[j]==0)
				j++;
			else
				break;
		}

		for(i=max; i>=(j+1); i--)
		{
			if(fact[i]==0)
			{
				continue;
			}
			else
			{
				printf("%ld %ld", i, fact[i]);
				fact[i]=0;
				printf(" ");
			}
		}

		printf("%ld %ld\n", j, fact[j]);
		fact[j]=0;
	}
	return 0; 
}