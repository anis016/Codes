#include<stdio.h>

long Z, I, M, L;
long count, test=1, hold;

int main()
{
	while(scanf("%lld %lld %lld %lld", &Z, &I, &M, &L), Z, I, M, L)
	{
		   L=((Z*L)+I)%M;

		   hold=L;
		   count=0;
		   while(1)
		   {
		     L=((Z*L)+I)%M;

		       count++;
			   if(hold==L)          /////////if visited the item will be as beginning
			   {
				   printf("Case %lld: %lld\n", test++, count);
				   break;
			   }
			  
		   }
	}

	return 0;
}