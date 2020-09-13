#include<stdio.h>
#include<math.h>

typedef unsigned long long tall;

int main()
{
  long long n, m, take;
  tall i,h,j,k,t;

  while(scanf("%lld %lld",&n, &m)==2)
  {
	  i=h=1;
	  j=k=0;
	  
	  while(n>0)
	  {
		  if(n%2==1)
		  {
			  t=j*h;
			  j=i*h + j*k +t;
			  i=i*k + t;
		  }
		  
		  t=h*h;
		  h=2*k*h + t;
		  k=k*k + t;

		 n=(tall) n/2;
	  }
	  
	  take=pow(2, m);
	  printf("%llu\n",j%take);
  }

  return 0;
}