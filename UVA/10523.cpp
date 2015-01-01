#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10000
char A[MAX];

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

/************************************************************************************/

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

/*************************************************************************************/

int main()
{
//	freopen("in.txt", "r", stdin);
	
	char fir[MAX],sec[MAX],res[MAX], xx[MAX], ith[MAX], power[MAX], res1[MAX];
	long len_f, len_s, N, a, i;

	while(gets(xx))
	{
		sscanf(xx, "%ld %ld", &N, &a);
		sprintf(A, "%ld", a);

		if(a==0)
		{
			printf("0\n");
			continue;
		}
		else if(N == 1)
		{
			printf("%d\n",a);
			continue;
		}

		strcpy(power, A);

	    for(i = 1; i <= N; i++)		 
		{
			if(i > 1)
			{
				call_mult(A, power, res1);         // make power
				strcpy(A, res1);
			}

			strcpy(res, A);
		
			sprintf(ith, "%ld", i);
			call_mult(res, ith, res);

			strcpy(fir, res);
			if(i > 1)
			{
				len_f=strlen(fir);
				len_s=strlen(sec); 
				if(len_f>len_s)
					call_sum(fir,sec,res);
				else
					call_sum(sec, fir, res);

				strcpy(sec, res);
			}
			else
				strcpy(sec, fir);
		}

		printf("%s\n", res);

		memset(A, 0, sizeof(A));
	}     
	return 0;
}