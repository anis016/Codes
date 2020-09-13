#include<stdio.h>
#include<string.h>
#define MAX 20000

/***********************************************************************************************/

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

void reverse(char *from,char *to)
{
	long len,l;
	len=strlen(from);
	for(l=0;l<len;l++)
		to[l]=from[len-l-1];
	to[len]='\0';
}

/***********************************************************************************************/

void call_mult(char *first,char *sec,char *result)
{
	char F[MAX],S[MAX],temp[MAX];
	long f_len,s_len,f,s,r,t_len,hold,res;
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
			res=(F[f]-'0')*(S[s]-'0')+hold+(temp[f+s]-'0');
			temp[f+s]=res%10+'0';
			hold=res/10;
			if(f+s>r)
				r=f+s;
		}
		
		while(hold!=0)
		{
			res=hold+(temp[f+s]-'0');
			temp[f+s]=res%10+'0';
			hold=res/10;
			if(f+s>r)
				r=f+s;
			f++;
		}
	}
	for(r=r+1;r>0 && (temp[r]=='0' && temp[r-1]!='0');r--)
		temp[r]='\0';
	reverse(temp,result);
}

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

/***********************************************************************************************/

// formula : (n*n*n*n - 6*n*n*n + 23*n*n - 18*n + 24) / 24

char N[MAX], temp[20];
char Res1[MAX], Res2[MAX], Res3[MAX], Res4[MAX], Res[MAX];

char xx[MAX];
long test;

int main()
{
	long len_f, len_s;
//	freopen("in.txt", "r", stdin);

	gets(xx);
	sscanf(xx, "%ld", &test);

	while(test--)
	{
		temp[0] = '2', temp[1] = '4', temp[3] = '\0';

		scanf("%s",N);
		sscanf(N, "%ld", &len_f);

		if(len_f <= 5)
		{
			if(len_f == 0)
				printf("1");

			if(len_f == 1)
				printf("1");

			if(len_f == 2)
				printf("2");
			
			if(len_f == 3)
				printf("4");
			
			if(len_f == 4)
				printf("8");
			
			if(len_f == 5)
				printf("16");
		
			printf("\n");
			continue;
		}


		call_mult(N, N, Res1);
		call_mult(N, Res1, Res1);
		call_mult(N, Res1, Res1);
	
		call_mult("6", N, Res2);
		call_mult(Res2, N, Res2);
		call_mult(Res2, N, Res2);

		call_mult("23", N, Res3);
		call_mult(N, Res3, Res3);

		call_mult("18", N, Res4);

		if(maximum(Res1, Res2) == 1)
			call_minus(Res1, Res2, Res);
		else
			call_minus(Res2, Res1, Res);

		len_f=strlen(Res);
		len_s=strlen(Res3);
		
		if(len_f>len_s)
            call_sum(Res,Res3,Res);
		else
			call_sum(Res3,Res,Res);
		
		if(maximum(Res, Res4) == 1)
			call_minus(Res, Res4, Res);
		else
			call_minus(Res4, Res, Res);

		len_f=strlen(Res);
		len_s=strlen(temp);
		
		if(len_f>len_s)
            call_sum(Res,temp,Res);
		else
			call_sum(temp,Res,Res);

		call_div(Res, 24, Res);

		printf("%s\n", Res);
	}
	return 0;
}