#include <string.h>
#include <stdio.h>
#include <ctype.h>

double converter(char in[])
{
   long sum, i, len1, j, k, len ;
 //  char str2[1000];

   len1 = strlen(in);
   for (i=0, k=0; i<len1; i++)
   {
	   if( (in[i]>=65 && in[i]<=90) || (in[i]>=97 && in[i]<=122) )
	   {
		   in[k]=in[i];
		   k++;
	   }
		   
   }
   in[k]='\0';

   len=strlen(in);
   
   for(j=0; j<len; j++)
	   in[j]=tolower(in[j]);

   sum=0;
   for(j=0; j<len; j++)
	   sum+=in[j]-'a'+1;

   return sum;
}

int main(void)
{
   double len1, temp, len2;

   char str1[1000000], str2[1000000];
   
   double hold, small, big;
   
   long sum1, sum2;

   while(gets(str1))
   {
	    gets(str2);

	    len1 = converter(str1);
        len2 = converter(str2);

        sum1=0;
		sum2=0;

		 while(len1>=10)                                 /////////adding untill summation is less den 10
		 {
		     for(sum1=len1,len1=0; sum1!=0; sum1/=10)
			      len1+=sum1%10;
		 }
		   
		 while(len2>=10)                                 /////////adding untill summation is less den 10
		 {
		     for(sum2=len2,len2=0; sum2!=0; sum2/=10)
			      len2+=sum2%10;
		 }

		
		if(len1>len2)
		{
	       temp=len1;
	       len1=len2;
	       len2=temp;
		}
		 
		 small=len1;
         big=len2;

         hold=(small/big)*100;

		 printf("%.2lf %%\n", hold);
   }
     
   return 0;
}

