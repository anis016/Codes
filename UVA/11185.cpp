#include<stdio.h>
#include<string.h>

int main()
{
	long i, j=0, k, count, h, d=0, c; 
	char a[1000000]="0", res[1000000]="0";
	
	while(1)
	{
	   scanf("%ld", &i);
	   if(i<0)
	  	 break;
	   if(i==0)
		   printf("0\n");
	   else
	   {
	     k=0;
	     while(j++>=0)
		 {
		   if(i==0)
			 break;
	           a[k++]=i%3+48;
	            i=i/3;
		 }
    	    a[k]='\0';

		 d=strlen(a)-1;
		
		for(c=d,count=0, h=0; c>=0; c--)
		{
		  res[h]=a[c];
		   if(res[h]=='1')
			count++;
		    h++;
		}
		    
		res[h]='\0';
	    printf("%s\n", res);
	   
	   }

	}

	return 0;
}
