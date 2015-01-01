#include<stdio.h>
#include<string.h>

int main()
{
	char in[1000];
	long i,  j=0, flag,  len=0;

	while(gets(in))
	{
	   len=strlen(in);
 	  
	   flag=j;
	   
	   for(i=0; i<len; i++)
	   { 
		  flag=j;		 
		  
		  if(in[i]==34 && flag==0)
		  {
			j++;
			printf("``"); 
		  }
		  
		  else if(in[i]==34 && flag==1)
		  {
			j--;
			printf("\'\'");
		  }

		  else
			printf("%c", in[i]);
	   }
	  
	   printf("\n");
	}
	
	return 0;
}
