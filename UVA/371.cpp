#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long tall;

tall find_cycle_length(tall );

int main()
{
	tall p, q, j, l, t, flag;
    tall max=0; 

	while(scanf("%lld %lld",&p, &q)==2)
	{
		 flag=0;
		 max=0;
		 l=0;
		 t=0;

		 if(p==0 && q==0)
			break;

		 if(p<q)
			 swap(p, q);
		
		 if( (p==1 && q==0) || (p==1 && q==1) || (p==2 && q==1) )
		 {
			flag=1;
			printf("Between %lld and %lld, 1 generates the longest sequence of 3 values.\n", q, p);
		 }

		 else if(flag==0)
		 {
			 for(j=q; j<=p; j++)
			 {
				 l=find_cycle_length(j);
				 if(l>max && j>t)
				 {
					 max=l;
					 t=j;
				 }
			 }
			 printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", q, p, t, max-1);
		 }
	}
	return 0;
}

tall find_cycle_length(tall q)
{
	tall count=1;

	while(1) 
	{
		if(q==1) 
			break;
		
		else 
		{
			if(q%2!=0)
			{
				q=3*q+1;
				count++;
			}
			else
			{
				q=q/2;
				count++;
			}
		}
	}
	return count;
}
