#include<stdio.h>
#include<string.h>
#define MAX 10000

/***********************************************************************************************/

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
/***********************************************************************************************/
int main()
{
	long len,i,kk,l,exp;
	char fir[MAX],sec[MAX],res[MAX],len1,len2;
	while(scanf("%s%s",fir,sec)==2)                       //// fir=base ///// sec=power
	{
		if(strcmp(fir, "0") == 0 && strcmp(sec, "0") == 0)
			break;

		exp=0;
		l=strlen(sec);
		for(kk=0;kk<l;kk++)
			exp=exp*10+(sec[kk]-48);
		if(exp==0)
		{
			printf("1\n");
			continue;
		}
		
		len1=strlen(fir);
		len2=strlen(fir);
		if((len1==1||len2==1)&&(fir[0]=='0'||sec[0]=='0'))
		{
			printf("0\n");
			continue;
		}

		strcpy(res,fir);

		for(kk=0;kk<exp-1;kk++)
		{
			call_mult(fir,res,res);
		}

		len=strlen(res);
		for(i=0;i<len;i++)
			printf("%c",res[i]);
		printf("\n");
	}
	return 0;
}