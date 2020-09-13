// recurrence relation a[i] = a[i - 3] + a[i - 2] + 2 * a[i - 1]

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1001

struct List
{
	char digit[MAX + MAX + MAX];
}list[MAX];

/******************************************************************/

void reverse(char *from, char *to )
{
	int len=strlen(from);
	int l;
	for(l=0;l<len;l++)
	to[l]=from[len-l-1];
	to[len]='\0';
}

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

/***************************************************************/

void generate()
{
	char fir[MAX],sec[MAX], third[MAX], res[MAX], temp[MAX];
	long i, len_f, len_s;

	strcpy(list[1].digit, "2");
	strcpy(list[2].digit, "5");
	strcpy(list[3].digit, "13");
	
	for(i = 4; i <= 1000; i++)
	{
		strcpy(fir, list[i - 3].digit);
		strcpy(sec, list[i - 2].digit);
		strcpy(third, list[i - 1].digit); // 2 * 
		
		len_f=strlen(fir);
		len_s=strlen(sec);
		
		if(len_f > len_s)
            call_sum(fir,sec,res);
		else
			call_sum(sec, fir, res);

		call_mult(third, "2", temp);

		len_f=strlen(temp);
		len_s=strlen(res);
		
		if(len_f > len_s)
            call_sum(temp,res,res);
		else
			call_sum(res,temp,res);

		strcpy(list[i].digit, res);
	}
	return ;
}

int main()
{
	long n;

	generate();

	while(scanf("%ld", &n)==1)
		printf("%s\n", list[n].digit);

	return 0;
}
