#include<stdio.h>
#include<string.h>
#define MAX 10000000

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
  return extra;
}
/*******************************************************************/


char fir[MAX],res[MAX];

int main()
{
   tall remainder15, remainder55, remainder4, remainder100, remainder400;
   tall flag, flag3, flag4,  z=1;

   while(gets(fir))
   {
	   remainder15=remainder55=remainder4=remainder100=remainder400=0;
	   flag=flag3=flag4=0;

	   if(z)
		   z=0; 
	   else 
		   printf("\n");

	   remainder4=call_div(fir,4,res);
	   remainder15=call_div(fir,15,res);
	   remainder55=call_div(fir,55,res);   
	   remainder100=call_div(fir,100,res);
	   remainder400=call_div(fir,400,res);


	  if( ( (remainder4 == 0) && (remainder100 != 0) ) || (remainder400 == 0) )
	  {
		  flag=1;
		  printf("This is leap year.\n");
	  }
  
      if(remainder15==0)
	  {
		  printf("This is huluculu festival year.\n");
		  flag4=1;
	  }
	  
	  if(remainder55==0 && flag==1)
	  {
		  printf("This is bulukulu festival year.\n");
		  flag3=1;
	  }

	  if(flag!=1 && flag3!=1 && flag4!=1)
		  printf("This is an ordinary year.\n");   
   }
 return 0;

}

/***********************************************************************************************************************/
/*
#include<stdio.h>
#include<iostream>
using namespace std;

#define MAX 10000000

char in[MAX];
int main()
{
   long i, len;
   long remain15, remain55, remain4, remain100, remain400;
   long flag;
   long z=1, ordinary;
   
   while(gets(in))
   {
	   if(z==1)
		   z=0; 
	   else 
		   printf("\n");
	   
	 len=strlen(in);

	 flag=remain15=remain55=remain4=remain100=remain400=0;
	 ordinary=1;

     for(i=0; i<len; i++)
	 {
	   remain4 = (remain4*10+in[i]-'0')%4;
	   remain15 = (remain15*10+in[i]-'0')%15;
	   remain55 = (remain55*10+in[i]-'0')%55;
	   remain100 = (remain100*10+in[i]-'0')%100;
	   remain400 = (remain400*10+in[i]-'0')%400;
	 }

     if( (!remain4 && remain100) || !remain400 )
	 {
	   flag=1;
	   printf("This is leap year.\n");
	   ordinary=0;
	 }
   
     if( !remain15 )
	 {
	   printf("This is huluculu festival year.\n");
	   ordinary=0;
	 }

     if( !remain55 && flag==1)
	 {
	   printf("This is bulukulu festival year.\n");
	   ordinary=0;
	 }
   
	 if(ordinary==1)
	 {
	   printf("This is an ordinary year.\n");
	 }

   }

   return 0;
}
*/