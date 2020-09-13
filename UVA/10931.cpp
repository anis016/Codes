#include<iostream>
using namespace std;
#include<string.h>

int main()
{
	long i, j=0, k, count, h, d=0, c; 
	char a[100]="0", res[100]="0";
	
	while(scanf("%ld", &i)!=EOF)
	{
	   if(i==0)
			break;
	   k=0;
	   while(j++>=0)
	   {
		if(i==0)
			break;
	     a[k++]=i%2+48;
	     i=i/2;
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

	    printf("The parity of %s is %ld (mod 2).\n", res, count);

	 }

	return 0;
}
