#include<stdio.h>
#include<string.h>

int main()
{
	char c, a[100001], b[100001];
	long int i,lena,sum,lenb,t;
     b[0]=0;
     lenb=0;
     while(gets(a))
	 {
		 if(strcmp(a,"0")==0)
            break;
	   
		 lena=strlen(a);
	     sum=0;
	   
		 for(i=0;i<=lena/2;i++)
		 {
		    c=a[i];
		    a[i]=a[lena-1-i];
		    a[lena-1-i]=c;
		 }
         t=lena;

         if(t>lenb)
           t=lenb;
         
		 sum=0;
	   
         for(i=0;i<t;i++)
		 {
		    sum=sum+(a[i]-48)+(b[i]-48);
		    b[i]=sum%10+48;
		    sum=sum/10;
		 }
       
		 for(i=t;i<lena;i++)
		 {
		    sum=sum+(a[i]-48);
		    b[lenb]=sum%10+48;
		    sum=sum/10;
		    lenb++;
		 }
       
		 for(i=t;i<lenb;i++)
		 {
		    sum=sum+(b[i]-48);
		    b[i]=sum%10+48;
		    sum=sum/10;
		 }
       
		 while(sum!=0)
		 {
	        b[lenb]=sum%10+48;
	        sum=sum/10;
	        lenb++;
		 }
       }
	     
	   for(i=lenb-1;i>=0;i--)
	   printf("%c",b[i]);
	   printf("\n");
   return 0;
}


