#include<stdio.h>
#include<math.h>

int main()
{
	long min, max, i, j, count,w,hold ;
		
	while(scanf("%ld %ld", &min, &max), min, max)
	{
	   count=0;
	   for(i=min; i<=max ; i++)
	   {
		   hold=long(sqrt(i));
		       if((hold*hold)==i)
			   	 count++;
	   }
	   printf("%ld\n", count);
	}
	return 0;
}
