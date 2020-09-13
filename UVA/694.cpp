#include<stdio.h>

int main()
{
	long A, L, j, count=0, test=1, AA=0, LL=0; 

	while(scanf("%lld %lld",&A, &L)==2)
	{
		AA=A;
		LL=L;
	  if(A<0 && L<0)
			break;
	  else
	  {
		   count=0;
		   for(j=A; j<=L; j++)
		   {
			   count++;
			   
			   if(A%2!=0)
			   {
						A=3*A+1;
			   }
			   else
			   {
						A=A/2;
			   }
			   if(A>L)
			   {
				   count--;
			         break;
			   }
			   if(A==1)
				   break;
					

		   }
		   
	  }
	
	  printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",test++, AA, LL, count+1);
	
	}
	return 0;
}
