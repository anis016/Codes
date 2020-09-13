#include<stdio.h>
#include<math.h>
#define MAX 32768

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
	con=del=hel=0;
	for(j=2; j<=(in/2); j++)
	{
		del=in-j;
		hel=j;

	    if( (prime[del]==0) && (prime[hel]==0) )
		{
			con++;
		}
	}    
	printf("%ld\n",con); 
		
   }
   return 0;
}

/***********************************************************************************************/
// DP
/*
#include<stdio.h>
#include<math.h>
#define MAX 32768

typedef long tall;

tall prime[MAX];
tall in, i, j, del, hel, con,ii,hold[MAX],g;

int main()
{
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

    g=4;
    for(ii=4; ii<32769; ii=ii+2)
	{
		con=del=hel=0;
		
		for(j=2; j<=(ii/2); j++)
		{
			del=ii-j;
			hel=j;

			if( (prime[del]==0) && (prime[hel]==0) )
			{
				con++;
			}
		}
		hold[g]=con;
		g=g+2;
	}
	
	while(scanf("%ld", &in), in)
		printf("%ld\n", hold[in]);
		
   return 0;
}
*/