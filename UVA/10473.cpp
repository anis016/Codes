#include<stdio.h>
#include<string.h>
#include<math.h>

void hexa_conversion(char a[])
{
	long count=0, i, len, t;

  	 len=strlen(a);   
	   for(i=0, t=len-1; i<len; t--, i++)
	   {
		  count+=(a[i]-48)*pow(10, t);
	   }

	  printf("0x%X\n", count);
	  return ;
}

void decimal_conversion(char a[])
{
	long count, i, len, t;

  	   len=strlen(a);   
	   count=0;
	   
	   for(i=2, t=len-3; i<len; t--, i++)
	   {
		   if( (a[i]>=48) && (a[i]<=57) ) 
			   count+=(a[i]-48)*pow(16, t);
			   
		   else if( (a[i]>=97) && (a[i]<=102) )
			   count+=(a[i]-87)*pow(16, t);
		   
		   else
		       count+=(a[i]-55)*pow(16, t);
	   }
	   printf("%ld\n", count);
	   return ;
}

int main()
{
	long len;
	char in[1000]; 

	while(gets(in))
	{	   
	   len = strlen(in);

	   if(in[0]=='-')
			break;
	   else
	   {
		 if(in[0]=='0' && in[1]=='x')
		 {
		     decimal_conversion(in);
		 }
		 else
		 {
			 hexa_conversion(in);
		 }
			
	   }

	 }

	return 0;
}
