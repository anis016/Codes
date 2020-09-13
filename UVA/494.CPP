#include<stdio.h>
#include<string.h>

int main()
{
 char in[900000];
 long i, count=0, flag, len=0;
 
 while(gets(in))
 {
	 count=0;
	 flag=0;
	 len=strlen(in);
	 for(i=0; i<len; i++)
	 {	     	 
		 if( (in[i]>=33 && in[i]<=64) || (in[i]>=91 && in[i]<=96) ||(in[i]>=123 && in[i]<=127) && flag==1)
		 {
			 flag=0;
		 }
		 if( ( (in[i]>='A' && in[i]<='Z') || (in[i]>='a' && in[i]<='z') ) && flag==0)
		 {
			 count++;
			 flag=1;
		 }
		 else if(in[i]==' ')
		 {
			 flag=0;
		 }

	 }
	 printf("%ld\n", count);
 }

 return 0;
}