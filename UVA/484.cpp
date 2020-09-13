#include<stdio.h>

int main()
{
    long long A[100000], B[100000];
	long long i=0, t, n=0, p=0, l, x;

	while(scanf("%lld", &x)!=EOF)
	{
		t=0;
		for(i=0; i<p; i++)
		{
			if(x==A[i])
			{
				B[i]++;
				t=1;
				break;
			}
		}
		if(t==0)
		{
			A[p]=x;
			B[p]=1;
			p++;
		}
	}
	for(l=0; l<p; l++)
		printf("%lld %lld\n", A[l], B[l]);
	return 0;
}
