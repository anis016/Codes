#include<stdio.h>
#include<math.h>
#define max 100000

typedef long tall;

int main()
{
	tall store[max], in, test, i, j, sum=0, length, hold, hc, hv, flag, k, kk;
	double ho;
	
	scanf("%lld", &test);
	for(kk=1; kk<=test; kk++)
	{
	  scanf("%lld", &in);
	  hold=in;

	  flag=0;
	  k=0;
	  store[k]=in;
	  k++;
	  while(1)
	  {

	   ho=length=0;

  	   ho = log10(in);
         length = long(floor(ho)+1);
	   sum=0;
	   for(i=0; i<length; i++)
	   {
		  hc=in%10;
		  sum+=pow(hc, 2);
		  hv=in/10;
		  in=hv;
	   }
	   if(sum==1)
	   {
		  flag=1;
		  break;
	   }
	   else if(sum==in)
	   {
		  flag=2;
		  break;
	   }
	   else 
	   {
		  store[k]=sum;
		  k++;
		  for(j=0; j<(k-1); j++)
			  if(store[j]==sum)   //////// checking if available
			  {
				  flag=2;
				  break;
			  }
			  else
			  {
			      in=sum;
			  }		 
	   }
	   if(flag==2)
	   {
		  break;
	   }
	  }

	 if(flag==1)
		printf("Case #%lld: %lld is a Happy number.\n", kk, hold);
	 else if(flag==2)
		printf("Case #%lld: %lld is an Unhappy number.\n", kk, hold);
	}
	return 0;
}