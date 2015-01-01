#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

#define MAX 1000

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
    char F[MAX], S[MAX], Res[MAX];
    long f,s,sum,extra,now;

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

int main()
{
     char *fibo[5001]={0};   /////////can count till 5000

	 fibo[0]="0";
     fibo[1]="1";

	 long l1=strlen(fibo[0]);
	 long l2=strlen(fibo[1]);

	 long l;

	 for(long i=2;i<=5000;i++)
	 {
		char str[10000];

		if(l1>=l2)
			l=l1;
		else l=l2;

		long ca=0;
		long j,k,m,p;

		for(j=l1-1,k=l2-1,m=0,p=0;p<l;j--,k--,m++,p++)
		{
			long s1;

			if(j<0)
				fibo[i-2][j]='0';

			s1=fibo[i-2][j]-48;

			long s2;

			if(k<0)
				fibo[i-1][k]='0';
			
			s2=fibo[i-1][k]-48;

			long ans=0;

			ans+=s1+s2+ca;

			if(ans>9)
			{

				str[m]=(ans-10)+48;
				ca=1;
			}
			else
			{
				str[m]=ans+48;
				ca=0;
			}
		}

		if(ca>0)
		{
			str[m]=ca+48; 
			m++;
		}
		 str[m]='\0';

		 fibo[i]=new char[m+1];
		 long y=0;

		 for(long x=m-1;x>=0;x--,y++)fibo[i][y]=str[x];
				fibo[i][y]='\0';
				l1=strlen(fibo[i-1]);
				l2=strlen(fibo[i]);
		}

////////////////////////////*****************************************////////////////////////////
//////////////////////////  *ALL FIBO BELOW 5000 IS STORED IN fibo[]*  //////////////////////////
////////////////////////////*****************************************////////////////////////////

    	long n;
		
		char res[MAX];
	    while(scanf("%ld", &n)!=EOF)
		{
//			cout<<fibo[n]<<"  "<<fibo[n+1]<<endl;

       	  call_sum(fibo[n+1], fibo[n], res);
        
		  long len=strlen(res);
        
		  for(long i=0;i<len;i++) 
			 printf("%c",res[i]);
        
		   printf("\n");
		}
        return 0;
}
