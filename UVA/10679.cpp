#include<stdio.h>
#include<string.h>
#define max 100000

char in1[max], in2[max], test[max], test3[max];
long len1, len2, k, ii, jj, test1, test2, j, flag;

int main()
{
	gets(test);
	sscanf(test, "%ld", &test1);

	for(ii=0; ii<test1; ii++)
	{
		gets(in1);
	
  	    gets(test3);
		sscanf(test3, "%ld", &test2);
		
		for(jj=0; jj<test2; jj++)
		{
			flag=0;
		  gets(in2);

          len1=strlen(in1);
	      len2=strlen(in2);          /////////in1 holds the first value in2 holds the next value
	   
	     if(len2>len1)
		      printf("n\n");
	      
		 else
		 {
			 k=0;
		     for(j=0; j<len2; j++)
			 {
				 if(in1[j]==in2[j])
				 {
					  k++;
				 }
				 else
				 {
					 flag=1;
					 break;
				 }
			 }
			 if(k==len2)
				 printf("y\n");
			 else if(flag==1)
				 printf("n\n");
			 else 
				 printf("n\n");
		  }
	   }
	}

    return 0;
}