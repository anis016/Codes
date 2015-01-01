#include<stdio.h>
#include<math.h>
#define MAX 20000000

typedef long tall;

tall a[MAX+100];
tall is_prime[MAX+100];
tall twin1[MAX+100];
tall twin2[MAX+100];

tall in, i, j, l, t, M, k;

void init()
{
	M=sqrt(MAX);
	
	for(i=3;i<=M;i+=2)
		if(a[i]==0)
			for(j=i*i;j<=MAX;j=j+i+i)
				a[j]=1;

	
	is_prime[1]=2;
	for(k=3, t=2; k<=MAX; k=k+2)
		if(a[k]==0)
		{
			is_prime[t]=k;
			t++;
		}
}

int main()
{
	init();

	for(i=1; i<t; i++)
	{
		if(is_prime[i+1]-is_prime[i]==2)
		{
			twin1[l]=is_prime[i];
			twin2[l]=is_prime[i+1];
			l++;
		}
	}

    while(scanf("%ld",&in)!=EOF)
    {
	   printf("(%ld, %ld)\n", twin1[in-1], twin2[in-1]); 
    }
    return 0;
}
