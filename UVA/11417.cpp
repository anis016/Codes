#include<stdio.h>

long GCD(long , long );

int main()
{
	long N, G; 
    long i, j;
    
	while(scanf("%ld", &N)!=EOF)
	{
		if(N==0)
			break;
	   
	   G=0;
       for(i=1;i<N;i++)
       for(j=i+1;j<=N;j++)
	   {
         G+=GCD(i,j);
	   }
	   printf("%ld\n", G);
	}
	   return 0;
}

long GCD(long a , long b)
{
	if(b==0)
		return a;
	else
		return GCD(b, a%b);
}
