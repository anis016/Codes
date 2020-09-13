#include<stdio.h>

long find_cycle_length(long );
long find_max_len(long, long);

int main()
{
	long len, p, q;

	while(scanf("%ld %ld",&p, &q)==2)
	{
		if(p<q)
		{
			len = find_max_len(p, q);
		}
		else
		{
			len = find_max_len(q, p);
		}
		
		printf("%ld %ld %ld\n", p, q, len);
		
	}
	return 0;
}

long find_max_len(long a, long b)
{
	long j, max=0, l; 
		
	    for(j=a; j<=b; j++)
		{
			l=find_cycle_length(j);
		    if(l>max)
				max=l;
		}
		return max;
}

long find_cycle_length(long q)
{
	long count=1;

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