#include<stdio.h>

long num, sum=0, sum2=0, i, j, k, a, s, array[100], out[100], t ;

int main()
{
	printf("PERFECTION OUTPUT\n");
	while(scanf("%ld",  &num), num)
	{
	   
	   sum=0;
	   for(i=1, j=0; i<num; i++)
	   {
		 if(num%i==0)
		 { 
			array[j]=i;
			j++;
		 }
	   }
  	   
	   for(k=0; k<j; k++)
		   sum+=array[k];
	       
		   if(sum==num)
		     printf("%5ld  PERFECT\n", num);
	       else if(sum<num)
		     printf("%5ld  DEFICIENT\n", num);
	       else if(sum>num)
		     printf("%5ld  ABUNDANT\n", num);
	 }
	   printf("END OF OUTPUT\n");

	return 0;

}