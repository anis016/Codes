#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5005

int sort_string(const void *a, const void *b)
{
	return (strcmp( (char*)a, (char*)b ) );
}

int equal(char *in1, char *in2)
{
	long i, len1, len2, count;

	len1=strlen(in1);
	len2=strlen(in2);

	if(len1!=len2)
		return 0;

	count=0;
	for(i=0; i<len1; i++)
	{
		if(in1[i]==in2[i])
			count++;
		else
			break;
	}
	if(count==len1)
		return 1;
	else
		return 0;
}

/*******************************************************************/

void reverse(char *from, char *to )
{
    int len=strlen(from);
    int l;

	for(l=0;l<len;l++)
      to[l]=from[len-l-1];
    
	to[len]='\0';
}

/******************************************************************/

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
   } 

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
	 }
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
}

char in[MAX], ascend[MAX], dscend[MAX], res[MAX], hold[MAX], search[MAX+100][MAX+100], hold1[MAX], hold2[MAX];

int main()
{
	long len,i,j,k,count,l,flag,a,x,t;
    
	while(gets(in))
	{
		if(equal("0", in)==1)
			break;
		else
		{
			strcpy(hold,in);
		
		   printf("Original number was %s\n", in);

		  count=l=flag=0;
	     while(1)
		 {
		   if(flag==1)
			 break;

		   len=strlen(hold);
    
		   qsort((void *)hold, len, sizeof(in[0]), sort_string);
	
		   for(i=0, j=0; i<len; j++, i++)
			  hold1[j]=hold[i];
		   hold1[j]='\0';

		   if(equal(hold1,"0")==0)
		   {
		   a=x=0;
		   for(i=0;i<j;i++)
		   {
			   if(hold1[i]=='0' && x==0)
				   continue;
			   else
			   { 
				   x=1;
				   ascend[a]=hold1[i];
				   a++;
			   }
		   }
		   ascend[a]='\0';
		   }
		   else
			   strcpy(ascend, hold1);
    
		   for(i=len-1, j=0; i>=0; j++, i--)
			  hold2[j]=hold[i];
		   hold2[j]='\0';
    
		   if(equal(hold2,"0")==0)
		   {
		   a=x=0;
		   for(i=0;i<j;i++)
		   {
			   if(hold2[i]=='0' && x==0)
				   continue;
			   else
			   { 
				   x=1;
				   dscend[a]=hold2[i];
				   a++;
			   }
		   }
		   dscend[a]='\0';
		   }
		   else
			   strcpy(dscend, hold2);

		   call_minus(dscend, ascend, res);
		   
		   printf("%s - %s = %s\n", dscend, ascend, res);

		   strcpy(hold,res);

		   strcpy(search[l], hold);
		   l++;
		  
		   for(t=0; t<(l-1); t++)
			  if(equal(search[t], hold)==1)
				 flag=1;
  	  	   count++;
		 }
		 printf("Chain length %ld\n", count);
		}
		printf("\n");
	}
	return 0;
}