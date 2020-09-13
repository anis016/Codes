#include<stdio.h>
#include<math.h>
#define MAX 1000000

typedef long tall;
tall prime[MAX+5];

long reverse(long b)
{
	long c;
	c=0;
	while(b>0)
	{
		c=c*10;
		c=b%10+c;
		b=b/10;
	}
	return c;
}

int main()
{
  tall in, i, j, ulta;

   prime[0]=prime[1]=1; 
   for(i=2; i<=sqrt(MAX); i++) 
   {
	   if(prime[i]==0) 
	   { 
		   for(j=i*i; j<=MAX; j=j+i) 
		   { 
			   prime[j]=1;               /////////// prime which are not prime are given value 1
		   } 
	   } 
   }

   while(scanf("%ld", &in)!=EOF)
   {
	   ulta=0;

	   if(prime[in]==1)
		   printf("%ld is not prime.\n", in);
	   else
	   {
		   ulta=reverse(in);
		   if(ulta==in && prime[in]==0)
			   printf("%ld is prime.\n", in);
		   else if(prime[ulta]==0 && prime[in]==0)
			   printf("%ld is emirp.\n", in);
		   else
			   printf("%ld is prime.\n", in);
	   }
   }
	   return 0;
}