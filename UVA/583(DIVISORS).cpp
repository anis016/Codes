#include<stdio.h>
#include<math.h>
#define MAX 700000

long a[MAX+200];
long is_prime[MAX+200];
long fact[MAX];
	
long i,j,k,M,t;

void init()
{
	M=(long)sqrt(MAX);
	
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
	long in, x, hold, g, hv, xx, tt, MM, dd;
	
	init();
	
	while(scanf("%ld", &in), in)
	{
		x=hold=g=hv=xx=tt=0;
		printf("%ld = ", in);

		if(in==1)
			printf("1\n");
		else if(in==-1)
			printf("-1\n");
		
		else 
		{
			if(in<0 )
			{
				in=in*-1;
				printf("-1 x ");
			}

			hold=g=hv=tt=dd=0;
			MM=(long)sqrt(in);
			for(x=0; is_prime[x]<=MM; x++)
			{
				while(in%is_prime[x]==0)
				{
					hv=in/is_prime[x];
					if(hold==0)
						fact[g]=is_prime[x], g++;
					in=hv;
				}
			}
			
			if(in>1)
				fact[g]=in, g++;
			
			tt=g;
			for(xx=0; xx<g; xx++)
			{
				printf("%ld", fact[xx]);
				if((tt-1)!=0)
					printf(" x ");
				tt--;
				fact[xx]=0;
			}
			printf("\n");
		}
	}
	return 0; 
}