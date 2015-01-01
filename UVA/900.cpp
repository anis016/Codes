#include<stdio.h>

long conquer_fibonacci(long n)
{
   long i,h,j,k,t;
   
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

	 n=(long) n/2;
   }
   
   return j;
}

int main()
{
  long n,res, res1;
  while(scanf("%ld",&n), n)
  {
	  res=res1=0;
	  if(n==1)
		  printf("1\n");
	  else
	  {
		  res=conquer_fibonacci(n);
		  res1=conquer_fibonacci(n-1);
		  printf("%ld\n",res+res1);
	  }
  }

  return 0;
}

/********************************************************************************/
/*
#include<stdio.h>

#define MAX 50

long fibo[1000];
long i, j, k, a, b, n;

int main()
{

	fibo[0]=0;
	fibo[1]=1;
	
	for(i=2; i<MAX; i++)
	{
		a=fibo[i-1];
		b=fibo[i-2];
		fibo[i]=a+b;
	}

	while(scanf("%ld", &n), n)
	{
		printf("%ld\n",fibo[n]+fibo[n-1]);
	}
	return 0;
}
*/
/**********************************************************************************/