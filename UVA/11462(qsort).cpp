#include <stdlib.h>
#include <stdio.h>
long m[2000000];

int fun_name(  const void *a, const void *b )
{
	long *p = (long *)a;  //Convert It your working type..(here int)
	long *q = (long *)b;  //Convert It your working type..(here int)

	
	return *p - *q ;   // 1st - 2nd if Increasing
}

int main()
{
	long i,j,n,tt,N;
	while(scanf("%ld",&n), n)
	{
       tt=n;
            
       for(i=0;i<n;i++)
       scanf("%ld",&m[i]);
		 
	   qsort( m, n, sizeof(long), fun_name );
	
	   for( j=0;j<n;j++)
	   {
		  printf("%ld",m[j]);
		    
           if((tt-1)!=0)
           {
               printf(" ");
               tt--;
           }
       }
    
	   printf("\n");
    }
	return 0;
}
