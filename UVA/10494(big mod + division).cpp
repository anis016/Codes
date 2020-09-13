#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
#define MAX 100000

typedef long tall;
 
/*******************************************************************/
tall call_div(char *number,tall div,char *result)
{
  tall len=strlen(number);
  tall now;
  tall extra;  
  char Res[MAX];
  
  for(now=0,extra=0;now<len;now++)
  {
    extra=extra*10 + (number[now]-'0');
    Res[now]=extra / div +'0';
    extra%=div;
  }
  Res[now]='\0';

  for(now=0;Res[now]=='0';now++)
	  ;
  strcpy(result, &Res[now]);
   
  if(strlen(result)==0)
     strcpy(result, "0");

  return extra;
}
/*******************************************************************/
int main()
{
   char fir[MAX],res[MAX], op, in[MAX], sec1[MAX];
   tall sec=0,remainder, i, j, ii, jj, t;
   tall len;
   while(gets(in))
   {
	   len=strlen(in);
	   for(i=0, j=0; i<len; i++)
	   {
		   if(in[i]>='0' && in[i]<='9')
		   {
			  fir[j]=in[i];
			  j++;
		   }	 
		   else if(in[i]=='/' || in[i]=='%')
		   {
			   op=in[i];
				  break;
		   } 
	   }
	   fir[j]='\0';

	   for(ii=i+1, jj=0; ii<len; ii++)
	   {
		   if(in[ii]>='0' && in[ii]<='9')
		   {
			   sec1[jj]=in[ii];
			     jj++;
		   }
	   }
	   sec1[jj]='\0';

	   sec=atol(sec1);
	   
    	if(op=='/')
		{
		   remainder=call_div(fir,sec,res);
		   
		   tall len1=strlen(res);
		   
		   for(t=0;t<len1;t++) 
			  printf("%c",res[t]);
		}
		else if(op=='%')
        {
		   remainder=call_div(fir,sec,res);
 		   
		   printf("%lld",remainder);
		}
      
		printf("\n");

   }

   return 0;
}

