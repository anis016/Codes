#include<stdio.h>
#include<math.h>
#define MAX 32000

unsigned int a[MAX+9];
unsigned int is_prime[MAX+10];
					
void generate_prime()
{
	unsigned int i,j,k,M,t;
	
	M=(unsigned int)sqrt(MAX);
	
	for(i=3;i<=M;i+=2)
		if(a[i]==0)
			for(j=i*i;j<=MAX;j=j+i+i)
				a[j]=1;

	
	is_prime[0]=2;
	for(k=3, t=1;k<=MAX;k=k+2)
		if(a[k]==0)
		{
			//printf("%ld ",k);
			is_prime[t]=k;
			t++;
		}
	return ;
}

unsigned int find_sum(unsigned int N)
{
	unsigned int sum = 0;
	while(N != 0)
	{
		sum += N % 10;
		N = N / 10;
	}
	return sum;
}

int Prime(unsigned int n)
{
	unsigned int i, m;

	if(n==1 || n==0)
		return 0;

	m = (unsigned int)sqrt(n); 
	
	for(i=2;i<=m;i++)
		if(n%i == 0)
			return 0;
	return 1;
}

void find_smith(unsigned int N, unsigned int &SumN)
{
	unsigned int i;

	unsigned int M = (unsigned int)sqrt(N);
	for(i = 0; is_prime[i] <= M; i++)
	{
		while(N % is_prime[i] == 0)
		{
			SumN += find_sum(is_prime[i]);
			N = N / is_prime[i];
		}
	}

	if(N > 1)
		SumN += find_sum(N);

	return ;
}

int main()
{
	generate_prime();

	unsigned int N, i, Case;

	scanf("%u", &Case);
	while(Case--)
	{
		scanf("%ld", &N);
		for(i = N + 1; true; i++)
		{
			if(Prime(i) == 1)
				continue;

			unsigned int res = find_sum(i);
			unsigned int sum = 0;
			find_smith(i, sum);
			
			if(sum == res)
				break;
		}
		
		printf("%u\n", i);
	}

	return 0;
}
