#include<stdio.h>
#define MAX 10000
#define SINF 999999
#define GINF 888888

long guess[MAX], secret[MAX], temp[MAX];
long high, low, outh[MAX], outl[MAX];

void check_high(long n)
{
	long i, j;

	high = 0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			if(secret[i]==guess[j] && i==j)
			{
				high++;
				guess[j] = GINF;
				secret[i] = SINF;
				break;
			}
			else if(i<j)
				break;
	}

	return ;
}

void check_low(long n)
{
	long i, j;

	low = 0;
	for(i=0; i<n; i++)				
	{
		for(j=0; j<n; j++)
		{
			if(secret[i]==guess[j] && (secret[i]<=9 && guess[j]<=9) && i!=j)
			{
				low++;
				guess[j] = GINF;
				secret[i] = SINF;
				break;
			}
			if(secret[i]>9) 
				break;
		}
	}

	return ;
}

int main()
{
	long n, k;

	long i, j, Case = 1, sum, flag;

	while(scanf("%ld", &n), n)
	{
		k=0;
		for(i=0; i<n; i++)
		{
			scanf("%ld", &secret[i]);
			temp[i] = secret[i];
		}

		while(1)
		{
			sum=flag=0;
			for(j=0; j<n; j++)
			{
				scanf("%ld", &guess[j]);
				secret[j] = temp[j];
				sum+=guess[j];
			}
			if(sum==0)
			{
				flag=1;
				break;
			}
			
			else
			{
				check_high(n);
				check_low(n);

				outh[k] = high;
				outl[k] = low;
				k++;
			}
		}

		printf("Game %ld:\n", Case++);
		for(i=0; i<k; i++)
			printf("    (%ld,%ld)\n", outh[i], outl[i]);
	}

	return 0;
}