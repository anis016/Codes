#include<stdio.h>
#include<math.h>
#include<string.h>

char S[1000], L[1000];

long todecimal(char *S1)
{
	long len=strlen(S1);
	long i, sum=0, j=0;

	for(i=len-1; i>=0; i--)
		sum+= ( (S1[i]-'0') * long((pow(2, j++))) );
	return sum;
}

long gcd(long a,long b)
{
	long t;
	while(a % b)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return b;
}

int main()
{
	char xx[1000];
	long hold1;
	long hold2;
	long final, test, count;

	gets(xx);
	sscanf(xx, "%ld", &test);

	count=1;
	while(test--)
	{
		hold1=final=hold2=0;

		gets(S);
		gets(L);
		
		hold1=todecimal(S);
		hold2=todecimal(L);

		final=gcd(hold1, hold2);

		if(final>1)
			printf("Pair #%ld: All you need is love!\n", count++);
		else
			printf("Pair #%ld: Love is not all you need!\n", count++);
	}
	return 0;
}
