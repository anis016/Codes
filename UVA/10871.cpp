#include<stdio.h>
#include<math.h>
#define MAX 50000

typedef long tall;

tall ho[MAX], c[MAX];
tall prime[MAX+100], n;

void init()
{
   tall i, j;

   prime[0]=prime[1]=0; 

   for(i=2; i<=sqrt(MAX); i++) 
   {
	   if(prime[i]==0) 
	   { 
		   for(j=i*i; j<=MAX; j=j+i) 
		   { 
			   prime[j]=1;
		   }
	   } 
   }

   return ;
}

int is_prime(long n)
{
	long i;

	if(n==1)
		return 0;
	if(n==2)
		return 1;
	if( (n%2)==0 )
		return 0;

	for(i=3; i*i<=n; i+=2)
		if( (n%i)==0 )
			return 0;

	return 1;
}

bool find_chain(long *n, long len)
{
	long sum, i;

	sum = 0;
	for(i=0; i<len; i++)
		sum+=n[i];

//	if(prime[sum]==0 || is_prime(sum)==1)
	if(is_prime(sum)==1)
		return true;
	else
		return false;
}

void read_case(void )
{
	long i;
	scanf("%ld", &n);
	for(i=0;i<n; i++)
	{
		scanf("%ld", &ho[i]);
	}
	return ;
}

int main()
{
   long Case;
   long i, p, j, k, z, s, st, t;
   bool flag;

 //  init();
   scanf("%ld", &Case);
   while(Case--)
   {
	   read_case();
	   flag = false;   
	   k = 2;
	   p = 2;
	   st = 0;
	   for(i=2; i<=n; i++)
	   {
		   s = 0;          // 6 4 5 4 12
		   z = 0;

		   while(k>=p)
		   {
			   z = s;
			   for(j=0, t=0; j<k; j++)
			   {
				   c[t] = ho[z];
				   t++;
				   z++;
			   }
			   s++;
			   flag = find_chain(c, k);
			   if(flag == true)
			   {
				   printf("Shortest primed subsequence is length %ld:", t);
				   for(i=0; i<t; i++)
				   {
					   printf(" %ld", c[i]);
					   c[i] = 0;
					   st = 1;
				   }
				   break;
			   }

			   if(n == z)
				   p++;
		   }
		   k++;
		   if(st == 1)
			   break;
	   }
	   if(flag == false)
	   {
		   printf("This sequence is anti-primed.");
	   }
	   printf("\n");
   }
   return 0;
}
