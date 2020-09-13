#include<stdio.h>
#include<string.h>

int main()
{
  char in[1000000];
	
  long i, len, sum, final=0, count=0, total, sum1;
	
  while(1)
  {
	gets(in);
	if(strcmp(in,"0")==0)
		break;
    else
	{
	    len=strlen(in);
	
	    final=0;
	    sum=0;
	     
		for(i=0; i<len; i++)
		  sum+=in[i]-48;
	
	    total=sum;
	
	    if(sum%9==0)
		{
		   printf("%s is a multiple of 9 and has 9-degree ", in);

		   sum1=0;
		   count=1;
		   final=sum;
	    
		   while(final>=10)                                 /////////adding untill summation is less den 10
		   {
		     for(sum1=final,final=0; sum1!=0; sum1/=10)
			 {
			  final+=sum1%10;
			 }
		     count++;
		   }
		   printf("%ld.\n", count);
		}
		else
		   printf("%s is not a multiple of 9.\n", in);   
	}
  }
	
	return 0;
}