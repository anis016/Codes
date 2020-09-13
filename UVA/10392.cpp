#include<stdio.h>
#include<math.h>
#define MAX 1000000
typedef long long LL;

LL a[MAX+10];
LL is_prime[MAX+10];
LL fact[MAX];

void init()
{
	LL i,j,k,M,t;

	M=(LL)sqrt(MAX);
	
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

int main()
{
	LL in, x, MM;
	
	init();
	
	while(scanf("%lld", &in) && in >= 0)
	{		
		MM=(LL)sqrt(in);
		for(x=0; is_prime[x]!= 0 && is_prime[x]<=MM; x++)
		{
			while(in%is_prime[x]==0)
			{
				printf("    %lld\n", is_prime[x]);
				in=in/is_prime[x];
			}
		}

		if(in > 1)
			printf("    %lld\n", in);

		printf("\n");
	}
	return 0; 
}