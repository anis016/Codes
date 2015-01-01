#include<stdio.h>
#include<math.h>
#define MAX 1000000

typedef long tall;

tall prime[MAX+5];

int main()
{
  tall in, i, j, del, hel, con;

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

   while(scanf("%ld", &in), in)
   {
	printf("%ld = ", in);

	con=del=hel=0;
	for(j=2; j<=(in/2); j++)
	{
		del=in-j;
		hel=j;

	    if( (prime[del]==0) && (prime[hel]==0) )
		{
			con=1;
			break;
		}
	}
	if(con==0) 
		printf("Goldbach's conjecture is wrong.\n"); 
	else
	    printf("%ld + %ld\n", hel, del); 
		
   }
   return 0;
}