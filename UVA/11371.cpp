#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int sorting(const void *a, const void *b)
{
	return ( strcmp( (char *)a, (char *)b) );
}

void reverse(char *from, char *to )
{
    int len=strlen(from);
    int l;

	for(l=0;l<len;l++)
      to[l]=from[len-l-1];
    
	to[len]='\0';
}

void call_minus(char *large, char *small, char *result)
{
   char L[MAX], S[MAX];
   int l,s,now,hold,diff;
  
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
//  return 1;
   
//  return sign;
}

int call_div(char *number,long div,char *result)
{
  int len=strlen(number);
  int now;
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

char in[MAX], in_ok[MAX], in_rev[MAX], hold[MAX], res[MAX], res_1[MAX];

int main()
{
	long len, i, j, k, remainder;
	char ch;

    while(gets(in))
	{
		if(in[0]=='0')
			printf("0 - 0 = 0 = 9 * 0\n");
		else
		{
			len=strlen(in);

			qsort(in, len, sizeof(in[0]), sorting);
	
			for(i=len-1, j=0; i>=0; j++,i--)
				in_rev[j]=in[i];
				in_rev[j]='\0';

			for(i=0, j=0; i<len; i++)
			{
				if(in[i]=='0')
				{
					hold[j]=in[i];
					j++;
				}
				else
				{
					ch=in[i];
					break;
				}
			}

			in_ok[0]=ch;
			for(i=0, k=1; i<j; k++, i++)
				in_ok[k]=hold[i];

			for(i=j+1; i<len; k++,i++)
				in_ok[k]=in[i];

			in_ok[k]='\0';

//	printf("%s\n", in_ok);

			call_minus(in_rev,in_ok,res);
			remainder=call_div(res,9,res_1);

			printf("%s - %s = %s = 9 * %s\n", in_rev, in_ok, res, res_1);
		}
	}
	
	return 0;
}
