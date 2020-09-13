#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100000

int main()
{
	char iin[MAX], in[MAX];
	long i, j, t, k, s, len1;

	while(gets(in))
	{
		i=j=t=k=s=len1=0;

		if(strcmp(in, "DONE")==0)
			break;
		else
		{
	      len1=strlen(in);
  	      for(j=0, s=0; j<len1; j++)
		  {
		    if( (in[j]>='A' && in[j]<='Z') )
			{
		       iin[s]=in[j]-'A'+'a';        ///// why cant use tolower???
			   s++;
			}
		    else if( (in[j]>='a' && in[j]<='z'))
			{
			   iin[s]=in[j];
			   s++;
			}
		    else 
			{
			   continue;
			}
		  }
	      iin[s]='\0';
	
          //  len=strlen(iin);       

	     for(i=0, t=s-1, k=0; i<s; t--, i++)
		 {
		   if(iin[i]==iin[t])
		   {
			 k++;
		   }
		 }
  	     if(k==s)
		    printf("You won't be eaten!\n");
		 else
		    printf("Uh oh..\n");
		}
	}	
	return 0;
}
