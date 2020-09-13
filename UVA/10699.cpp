#include<stdio.h>
#include<math.h>
#define MAX 1000000

long a[MAX];
long is_prime[MAX];
	
long i,j,k,M,t;
long count, ii, in;	

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
							//a[2]=0 FIXED
int main()
{
	init();

	while(scanf("%ld", &in), in)
	{
		count=0;
		
		for(ii=0; is_prime[ii]<in; ii++)
			if(in%is_prime[ii]==0)
				count++;
		
		if(count==0)
			count=1;
			
		printf("%ld : %ld\n",in, count);
	}
	return 0;
}