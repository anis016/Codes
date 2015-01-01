#include<stdio.h>
#include<string.h>

char in[1000000], xx[100000];
long len, test, i;

int main()
{
    gets(xx);
	sscanf(xx, "%ld", &test);
	
	for(i=0; i<test; i++)
	{
	  gets(in);

		len=strlen(in);
		
	       if( (strcmp(in, "1")==0) || (strcmp(in, "4")==0) || (strcmp(in, "78")==0) )
			       printf("+\n");
			        				
           else if(len>=2 && in[len-1]=='5' && in[len-2]=='3')
			       printf("-\n"); 
				    
           else if(in[0]=='9' && in[len-1]=='4')
		   	       printf("*\n");				
				  
           else if(len>=3 && in[0]=='1' && in[1]=='9' && in[2]=='0' )
			       printf("?\n");
			   
		   else
		   	       printf("\n");    
	}
	
	return 0;
}