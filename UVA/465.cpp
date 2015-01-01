#include<stdio.h>
#include<string.h>

#define MAX 100000

int maximum(char *in1, char *in2)
{
	long len1, len2, i;
	int flag=0;

	len1=strlen(in1);
	len2=strlen(in2);

	if(len1==len2)
	{
		for(i=0; i<len1; i++)
		{
			if(in1[i]==in2[i])
			{
				continue;
			}
			else if(in1[i]>in2[i])
			{
				return 1;
				break;
			}
			else if(in1[i]<in2[i])
			{
			    return -1;
				break;
			}
		}
	}

	else if(len1>len2)
		return 1;

	else if(len1<len2)
		return -1;
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

void call_sum(char *first, char *sec, char *result)
{
    char F[MAX], S[MAX], Res[MAX];
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

/******************************************************************/

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

char in[MAX], in1[MAX], in2[MAX], ch, res[MAX];
long lena, lenm, len_f, len_s, len, i, j, ii, jj, k, t, flag;

int main()
{
	while(gets(in)) 
	{
	   puts(in);

	   flag=0;
	   len=strlen(in);

	   for(k=0; k<len;)
	   {
		   while(1)
		   {
		     if(in[k]=='0' || in[k]==' ')
			 {
				 k++;
				 continue;
			 }
		     else
			 {
				flag=1;
			    break;
			 }
		   }
		   if(flag==1)
				break;
	   }
	   for(i=k, j=0; i<len; i++)
	   {
		   if(in[i]>='0' && in[i]<='9')
		   {
			  in1[j]=in[i];
			  j++;
		   }	 
		   else if(in[i]=='*' || in[i]=='+')
		   {
			   ch=in[i];
				  break;
		   } 
	   }
	   in1[j]='\0';

	   flag=0;t=0;
	   for(t=i+1; t<len; )
	   {
		   while(1)
		   {
		    if(in[t]=='0' || in[t]==' ')
			{
				t++;
				continue;
			}
		    else
			{
				flag=1;
			    break;
			}
		   }
		   if(flag==1)
				 break;
	   }
	   
	   for(ii=t, jj=0; ii<len; ii++)
	   {
		   if(in[ii]>='0' && in[ii]<='9')
		   {
			   in2[jj]=in[ii];
			     jj++;
		   }
	   }


	   in2[jj]='\0';
	   flag=0;
	    
	   if(ch=='+')
	   {
		  len_f=strlen(in1);
		  len_s=strlen(in2);
		 
		  if(len_f>len_s)
             call_sum(in1,in2,res);
		  else
			 call_sum(in2, in1, res);
        
		 lena=strlen(res);
		 res[lena]='\0';
		 
		 if(maximum(in1,"2147483647")==1)
			 puts("first number too big");
   
		 if(maximum(in2,"2147483647")==1)
			 puts("second number too big");

		 if(maximum(res,"2147483647")==1)
			 puts("result too big");
		}

		if(ch=='*')
		{			
		
		   call_mult(in1,in2,res);
		   lenm=strlen(res);
		   res[lenm]='\0';
			
		 if(maximum(in1,"2147483647")==1)
			 puts("first number too big");
      
		 if(maximum(in2,"2147483647")==1)
			 puts("second number too big");

		 if(maximum(res,"2147483647")==1)
			 puts("result too big");
		}
	}	
	return 0;
}