#include<stdio.h>
#include<string.h>
#define MAX 10000

char a[MAX];
char in[MAX];

int main()
{
	long i, sum, j ;

	while(gets(in))
	{
	  sum=0;
	  for(i=0; i<strlen(in); i++)
	  {
		if(in[i]>='a' && in[i]<='z')
			sum+=in[i]-'a'+1;
		else 
			sum+=in[i]-'A'+27;
	  }

     for(i=2;i<MAX;i++)
	  {
            if(a[i]!=1)
              for(j=i+i;j<MAX;j+=i)
                a[j]=1;
	  }
	  
      
          if(a[sum]==0)
             printf("It is a prime word.\n");
          else 
             printf("It is not a prime word.\n");
	}
	 	
	return 0;
}

