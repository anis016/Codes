#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX 2000

/*******************************************************************/

void reverse(char *from, char *to )
{
    long len=strlen(from);
    long l;

	for(l=0;l<len;l++)
      to[l]=from[len-l-1];
    
	to[len]='\0';
}

/******************************************************************/

void call_sum(char *first, char *sec, char *result)
{
    char F[MAX+100], S[MAX+100], Res[MAX+100];
    int f,s,sum,extra,now;

	f=strlen(first);
    s=strlen(sec);

	reverse(first,F);
    reverse(sec,S);

	for(now=0,extra=0;(now<f && now<s);now++)
	{
       sum=(F[now]-'0') + (S[now]-'0') + extra;
       Res[now]=sum%10 +'0';
       extra= sum/10;
	}
    
	for(;now<f;now++)
	{
       sum=F[now] + extra-'0';
       Res[now]=sum%10 +'0';
       extra=sum/10;
	}

	for(;now<s;now++)
	{
       sum=F[now] + extra-'0';
       Res[now]=sum%10 +'0';
       extra=sum/10;
	}
    
	if(extra!=0) 
		Res[now++]=extra+'0';

	Res[now]='\0';

	if(strlen(Res)==0) 
		strcpy(Res,"0");
    
	reverse(Res,result);
}

/*******************************************************************/

long call_div(char *number,long div,char *result)
{
  long len=strlen(number);
  long now;
  long extra;  
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


char fir[MAX+100], sec[MAX+100], res[MAX+100], xx[MAX+100], result[MAX+100];

int main()
{
     long len_f, len_s, j, test, remainder, second, len_d, lo=0, len_res;
	 	 
	 while(1)
	 {
		 second=0;
		 scanf("%ld", &second);

		 gets(xx);
	     sscanf(xx, "%ld", &test);

		 swap(second, test);
		 
		 if(test==0 && second==0)
			 break;

		 len_f=len_s=len_res=0;	 
		 strcpy(sec, "0");
		 
		 for(j=0; j<test; j++)
		 {         
		   gets(fir);
	   
	 	   len_s=strlen(sec);
		   len_f=strlen(fir);

		   if(len_f<len_s)		 
		      call_sum(sec, fir, res);
		   else
			  call_sum(fir, sec, res);
	
		   strcpy(sec, res);
		 }

		 len_res=strlen(res);
		 res[len_res]='\0';
 
		 len_d=remainder=0;
		 remainder=call_div(res,second,result);
	 
	     len_d=strlen(result);
	     result[len_d]='\0';

		 
		 printf("Bill #%ld costs %s: each friend should pay %s\n", ++lo, res, result);
		 printf("\n");	 
	 }
     return 0;
}
