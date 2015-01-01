#include<stdio.h>
#include<stdlib.h>

#define MAX 100000

int fun_name(  const void *a, const void *b )
{
	long *p = (long *)a;  
	long *q = (long *)b;  
	
	return *p - *q ;   
}

int main()
{
	long n, m, test=0, i, beg, end, mid, found, j, hold;
	long myarray[MAX], find[MAX];

	while(scanf("%ld %ld", &n, &m)==2)
	{
		if(n==0 && m==0)
			break;

		printf("CASE# %d:\n",++test);
	    
		for(i=0; i<n; i++)
			 scanf("%ld", &myarray[i]);
	
		qsort( myarray, n, sizeof(long), fun_name );

		for(i=0; i<m; i++)
			scanf("%ld", &find[i]);
		 		   
		for(i=0; i<m; i++)
		{
		   beg=end=mid=found=hold=0;
		   
		   if(find[i]==myarray[0])
		   	   printf("%ld found at 1\n", find[i]);

		   else
		   {
		     end=n-1;
		     mid=long((beg+end)/2);

		     while(beg<=end)
			 {
				 if(find[i]==myarray[mid])
				 {
					 found=1;
					 hold=mid;
					 break;
				 }

				 if(find[i]<myarray[mid])
				   end=mid-1;
			     else
				   beg=mid+1;

			    mid=long((beg+end)/2);
			 }

			 if(found==1)
			 {
				 for(j=0; j<hold; j++)
				 {
					  if(find[i]==myarray[j])
					  {
						  mid=j;
						  break;
					  }
				 }
				 printf("%ld found at %ld\n", find[i], mid+1);
			 }
		     else
			     printf("%ld not found\n", find[i]);
		   }
		}
	}
	return 0;
}