#include<stdio.h>
#include<math.h>

long divisors(long in)
{
	long M, i, j, k, countm, countd;

	countm=countd=0;
	M=sqrt(in);
	for(i=1; i<=M; i++)
	{
		j=in%i;
		k=in/i;

		if(j==0)
		{
			countm=(countm+2);
		}
	    if(j==0 && k==i)
		{
			countd=countm-1;
		}
		else
			countd=countm;
	}
	return countd;
}

int main()
{
	long max, min;
	long i, count, L, U, test;

	scanf("%ld", &test);

	while(test--)		
	{
		scanf("%ld %ld", &L, &U);

		count=0;
		max=0;
		min=0;
		for(i=L; i<=U; i++)
		{
			count=divisors(i);
			if(count>max)
			{
				max=count;
				min=i;
			}
		}
		printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n", L, U, min, max);
	}

	return 0;
}

/*
using prime seive way

#define MAXP 31623

long a[MAXP], isPrime[MAXP];
long frequency[MAXP];

long generatePrime() {
	long i, j, t, k;
	long M = (long)sqrt((double)MAXP);
	
	for(i=3; i<=M; i+=2) {
		if(a[i]==0)
			for(j=i*i;j<=MAXP;j=j+i+i) {
				a[j]=1;
			}
	}

	isPrime[0]=2;
	for(k=3, t=1; k <= MAXP; k=k+2) {
		if(a[k]==0) {
			isPrime[t]=k;
			t++;
		}
	}

	return t;
}

long getDivisor(long n) {

	long i = 0;
	while( isPrime[i] ) {
		if(n == 1)
			break ;

		if(n%isPrime[i] == 0) {
			frequency[isPrime[i]]++;
			n = n/isPrime[i];
		} else
			i++;
	}
	
	long k, sum = 1;
	for(k = i, i = isPrime[i]; k >= 0;i = isPrime[k]) {
		sum *= (1+frequency[i]);
		frequency[i] = 0;
		k--;
	}

	return sum;
}

int main() {

	long i, l, r, div, counter;
	long count = generatePrime();

	scanf("%ld", &counter);
	while(counter--) {
		scanf("%ld %ld", &l, &r);
		long index, maxValue = ninf;
		for(i = l; i <= r; i++) {
			div = getDivisor(i);
			if(div > maxValue) {
				maxValue = div;
				index = i;
			}
		}
		
		printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n", l, r, index, maxValue);
	}

	return 0;
}

*/