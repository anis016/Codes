#include<stdio.h>
#include<stdlib.h>
#define MAX 350
typedef long long ll;

const ll range =  2147483649;
ll mat[MAX];
ll J = 0;
ll mid;

int fun_name(  const void *a, const void *b )
{
	ll *p = (ll *)a;
	ll *q = (ll *)b;

	
	return *p - *q ;
}

ll Bsearch(ll N)
{
	ll low, high;

	low = 0;
	high = J - 1;

	while(low <= high)
	{
		mid = (low + high) / 2;

		if(mat[mid] == N)
			return mid;
		else if(N < mat[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

void generate()
{
	ll i, j;

	for(i=1; i<=range; i=i*2)
		for(j=1; j<=range; j=j*3)
			if( i * j > range) 
				break;
			else
				mat[J++] = i * j;

	qsort(mat, J, sizeof(ll), fun_name);
}

int main()
{
	ll N, K;

	generate();

	while(scanf("%lld", &N), N)
	{
		K = Bsearch(N);

		if(K == -1)
		{
			if(mat[mid] < N)
				printf("%ld\n", mat[mid + 1]);
			else
		        printf("%ld\n", mat[mid]);
		}
		else if(mat[K] == mat[mid])
			printf("%lld\n", mat[mid]);

		mid = 0;
	}
	return 0;
}
