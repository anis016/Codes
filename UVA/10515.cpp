#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 10000

char m[1111],n[1111],fir[10],sec[10],res[1111],digit[6][2];

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
	long i,r,num1,num2,len1,len2,pos1,pos2,len,k,j,nn,t;
	while(scanf("%s %s",m,n)==2)
	{
		len1=strlen(m);
		len2=strlen(n);

		digit[1][0]=m[len1-1];
		digit[1][1]=0;

		//sscanf(n,"%ld",&nn);
		if(len1==1 && m[0]=='0' && len2==1 && n[0]=='0')
			break;
		if(n[0]=='0')
		{
			printf("1\n");
			continue;
		}
		if(n[0]=='1' && len2==1)
		{
			printf("%c\n",m[len1-1]);
			continue;
		}
		if(m[0]=='0' && len1==1)
		{
			printf("0\n");
			continue;
		}
		if(m[0]=='1' && len1==1)
		{
			printf("1\n");
			continue;
		}
		if(len1>1)
			pos1=len1-1;
		else
			pos1=0;
		if(len2>2)
			pos2=len2-2;
		else
			pos2=0;

		k=0;
		for(i=pos1;i<len1;i++)
			fir[k++]=m[i];
		fir[k]=0;
		k=0;
		for(i=pos2;i<len2;i++)
			sec[k++]=n[i];
		sec[k]=0;

		num2=0;
		for(i=0;i<k;i++)
			num2=(num2*10)+(sec[i]-48);

		sec[0]=fir[0];
		sec[1]=0;
	
		for(i=0;i<3;i++)
		{
			k=0;
			call_mult(fir,sec,res);
			len=strlen(res);
			for(j=0;j<len;j++)
			{
				sec[k++]=res[j];
			}
			digit[i+2][0]=res[len-1];
			digit[i+2][1]=0;
			sec[k]=0;
		}
		t=num2%4;                         /////////for the last digit

		if(t==0)
			printf("%c\n",digit[4][0]);
		else 
			printf("%c\n",digit[t][0]);
	}
	return 0;
}