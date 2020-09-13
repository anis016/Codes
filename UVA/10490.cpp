#include<stdio.h>
#include<math.h>
#define MAX 2000000

unsigned long a[MAX]={0};

int main()
{ 
 long long i,j;
 long long p, hold;
 long double take, mers_prime;
 
 for(i=2;i<MAX;i++)  //for prime generation by schiff method
 if(a[i]!=1)
 {
  for(j=i+i;j<MAX;j+=i)
  a[j]=1;
 }

 while(scanf("%lld", &p), p)
 {
	 hold=0;take=0;
	 if(p==1)
	 {
		 printf("Given number is NOT prime! NO perfect number is available.\n");
	 }
	 else if(a[p]==0)
	 {
		 if( p==11 || p==23 || p==29 )
		 {
			 printf("Given number is prime. But, NO perfect number is available.\n");
		 }
			 
		 else
		 {
			 mers_prime=(pow(2, p)-1);
			 hold=p-1;
			 take=pow(2,hold)*mers_prime;
	         printf("Perfect: %.0Lf!\n",take);
		 }
			 
	 }
	 else
	 {
		 printf("Given number is NOT prime! NO perfect number is available.\n");
	 }
 }
return 0;
}
