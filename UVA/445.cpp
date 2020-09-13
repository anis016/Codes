#include<stdio.h>
#include<string.h>

int main()
{
	char in[1000];
	long i, len, j, y=0, s=0;

	while(gets(in))
	{
  	  len=strlen(in);

	  y=0;s=0;
	  for(i=0; i<=len; i++)
	  {
		//  s=0;
		if( (in[i]>=48 && in[i]<=57) )
		{
			 y=in[i]-48;
		  	 s+=y; 
		}
		if( (in[i]>=48 && in[i]<=57) && (in[i+1]>=65 && in[i+1]<=90) )
		{
			for(j=0; j<s; j++)
			  if(in[i+1]>=65 && in[i+1]<=90)
			  {
					  printf("%c", in[i+1]);
			  }
			  s=0;
		}
		if( (in[i]>=48 && in[i]<=57) && (in[i+1]==98) )
		{
			for(j=0; j<s; j++)
			  if(in[i+1]==98)
			  {
					  printf(" ");
			  }
			  s=0;
		}
		if( (in[i]>=48 && in[i]<=57) && (in[i+1]==42) )
		{
			for(j=0; j<s; j++)
			  if(in[i+1]==42)
			  {
					  printf("*");
			  }
			  s=0;
		}
		else if(in[i]==33)
			 printf("\n");
		
	  }
	  printf("\n");
	}
	return 0;
}
