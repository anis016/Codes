#include<stdio.h>
#include<math.h>

typedef long Llong;
#define MAX 10000001
#define MAXR 3162

Llong prime[MAX], a[MAX];

void generate()
{
	int i, j, l, t;

	for(i = 3; i <= MAXR; i+=2)
		if(a[i] == 0)
			for(j = i*i; j <= MAX; j += 2*i)
				a[j] = 1;

	for(l = 3, t = 1; l <= MAX; l += 2)
		if(a[l] == 0)
			prime[t++] = l;
	prime[0] = 2;

	return ;
}

Llong power(Llong base, Llong expo)
{
	Llong i, res = 1;
	for(i = 1; i <= expo; i++)
		res *= base;
	return res;
}

int main()
{
	Llong A, B, C;
	Llong i, Case, ii;

	generate();

	scanf("%lld", &Case);
	for(ii=1; ii<=Case; ii++)	
	{
		scanf("%lld %lld", &A, &C);

		if(C % A != 0)
		{
			printf("NO SOLUTION\n");
			continue;
		}

		i = 0;
		B = 1;
		while(prime[i] * prime[i] <= C)
		{
			Llong cntC = 0;
			Llong cntA = 0;

			while(A % prime[i] == 0)
			{
				A = A / prime[i];
				cntA++;
			}

			while(C % prime[i] == 0)
			{
				C = C / prime[i];
				cntC++;
			}

			if(cntC > cntA)
				B *= power(prime[i], cntC);

			i++;
		}

		if(C > 1 && A == 1)
			B = B * C;

		printf("%lld\n", B);
	}

	return 0;
}

