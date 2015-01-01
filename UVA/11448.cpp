#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 10000000

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

char L[MAX], S[MAX];

long call_minus(char *large, char *small, char *result)
{
   long l,s,now,hold,diff;
  
   l=strlen(large);
   s=strlen(small);
   
   bool sign = 0;
   
   if(l<s)
   {
	 strcpy(result,large);
	 strcpy(large,small);
	 strcpy(small,result);
	 now=l; 
	 l=s; 
	 s=now;
	 sign = 1;
   } //return 0;

   if(l==s)
   {
	 if(strcmp(large, small)<0)
	 {
		strcpy(result,large);
		strcpy(large,small);
		strcpy(small,result);

		now=l; 
		l=s; 
		s=now;
		sign =1;
	 }//return 0;
   }

   reverse(large,L);
   reverse(small,S);

   for(;s<l;s++)
	 S[s]='0';
	 S[s]='\0';
   for(now=0,hold=0;now<l;now++)
   {
	  diff=L[now]-(S[now]+hold);
	  if(diff<0)
	  {
	     hold=1;
		 result[now]=10+diff+'0';
	  }
	  else
	  {
		 result[now]=diff+'0';
	     hold=0;
	  }
   }

   for(now=l-1;now>0;now--)
   {
	  if(result[now]!='0')
	     break;
   }
   result[now+1]='\0';
	
   reverse(result,L);
   strcpy(result,L);
  //return 1;
   
   return sign;
}

char fir[MAX],sec[MAX],res[MAX];

int main()
{
   long Case;
   	
   scanf("%ld", &Case);
   while(Case--)
   {
	   scanf("%s%s",&fir,&sec);

	  if(call_minus(fir,sec,res)==1)
	     printf("-");

	  long len = strlen(res);
	
	  for(long i=0;i<len;i++)
          printf("%c",res[i]);

	  printf("\n");
   }
   return 0;
}