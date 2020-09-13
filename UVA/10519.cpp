#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
#define MAX 100000

/******************************************************************/
void reverse(char *from, char *to )
{
	int len=strlen(from);
	int l;
	for(l=0;l<len;l++)
	to[l]=from[len-l-1];
	to[len]='\0';
}
/******************************************************************/

int call_minus(char *large, char *small, char *result)
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
  //return 1;
   
   return sign;
}

/***************************************************************************************/

void call_mult(char *first,char *sec,char *result)
{
	char F[MAX],S[MAX],temp[MAX];

	int f_len,s_len,f,s,r,t_len,hold,res;

	f_len=strlen(first);

	s_len=strlen(sec);

	reverse(first,F);

	reverse(sec,S);

	t_len=f_len+s_len;

	r=-1;
		for(f=0;f<=t_len;f++)
			temp[f]='0';
			temp[f]='\0';
			for(s=0;s<s_len;s++)
			{
				hold=0;
				for(f=0;f<f_len;f++)
				{
					res=(F[f]-'0')*(S[s]-'0') + hold+(temp[f+s]-'0');
					temp[f+s]=res%10+'0';
					hold=res/10;
					if(f+s>r) r=f+s;
				}
				while(hold!=0)
				{
					res=hold+temp[f+s]-'0';
					hold=res/10;
					temp[f+s]=res%10+'0';
					if(r<f+s) r=f+s;
					f++;
				}
			}
	for(;r>0 && temp[r]=='0';r--);
	temp[r+1]='\0';
	reverse(temp,result);
}
/***************************************************************/
int main()
{
	char fir[MAX],sec[MAX],res[MAX], sec_1[MAX], res_1[MAX], f_res[MAX];
	long i, ii, len1, len2, f, f_len, hv;
	while(scanf("%s",&fir)==1)
	{
		 hv=atoi(fir);
		if(strcmp(fir, "0")==0 || hv==0)
			printf("1\n");                             /////// critical output
		else if(strcmp(fir, "1")==0 || hv==1)
			printf("2\n");
		else
		{
		  strcpy(sec, fir);             ///// doing power
		
		   call_mult(fir,sec,res);

		   strcpy(sec_1, "2");
		if(call_minus(fir,sec_1,res_1)==1)
	       printf("-");

		 len1 = strlen(res);
		 len2 = strlen(res_1);
		
		for(i=0;i<len1;i++) 
			  res[i];
		      res[i]='\0';                  /////// storing (m*m) value

//		printf("%s", res);
        
		for(ii=0;ii<len2;ii++)
              res_1[ii];                   //////// storing (m-2) value
 	          res_1[ii]='\0';

//      printf("%s", res_1);

		if(call_minus(res,res_1,f_res)==1)
	           printf("-");

        f_len=strlen(f_res);
		for(f=0; f<f_len; f++)
		    printf("%c", f_res[f]);

          printf("\n");
		}
	}
return 0;
}

//       sum=(m*m)-(m-2);
