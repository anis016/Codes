#include<stdio.h>
#include<string.h>
#define MAX 10000

char tl[MAX];
char top[MAX];
char temp[MAX];
char in[MAX];
char in_C[MAX];
char in1[MAX];

long hold[MAX];
long num[MAX];
long P_sum[MAX];

int main()
{
	long iii, len, an, lll, l, d, ddd, jjj, flag,fin;
	long i, j, k, sum, count, prime, as, has;

	while(gets(top))
	{
		if(strcmp(top, " ")==0)
		{
			printf("is incorrect.\n");
			continue;
		}

		len=strlen(top);

		an=0;
		for(iii=0, jjj=0; iii<len; iii++)
		{
			if(top[iii]==' ' && an==0)
				continue;
			else
			{
				tl[jjj++]=top[iii];
				an=1;
			}
		}

		an=0;
		for(d=jjj-1, ddd=0; d>=0; d--)
			if(tl[d]==' ' && an==0)
				continue;
			else
			{
				temp[ddd++]=tl[d];
				an=1;
			}
		
		for(l=ddd-1, lll=0; l>=0; l--)
			in[lll++]=temp[l];                  ////////// in contains the actual string

		count=j=prime=an=as=has=0;
		for(i=0; i<lll; i++)
		{
			if( (in[i]>='0' && in[i]<='9') || in[i]=='-' || in[i]=='X')
			{
				if(in[i]=='-')
				{ 
					continue;
				}
				
				if(in[i]>='0' && in[i]<='9')         /// taking only the integer value
				{
					hold[j]=in[i]-'0';
					j++;
					count++;
					prime++;
				}

				if(in[i]=='X' && count>=9)
				{
					hold[j]='j'-'a'+1;
					j++;
					count++;
					prime++;
				}
			}

			if( !(in[i]>='0' && in[i]<='9') && in[i]!='X')
			{
				prime++;
				printf("%s is incorrect.\n", in);        //// not correct
				an=2;
				
				for(i=0; i<lll; i++)
				{
					in1[i]=in[i]='\0';
					hold[i]=P_sum[i]=0;
				}
				as=1;
			}		
			if(as==1)
				break;
			
			if(in[i]=='X' && count>10)
			{
				prime++;
				printf("%s is incorrect.\n", in);        //// not correct
				an=2;
				
				for(i=0; i<lll; i++)
				{
					in1[i]=in[i]='\0';
					hold[i]=P_sum[i]=0;
				}
				as=1;
			}
			if(as==1)
				break;

			if( (in[i]=='X' && count!=10) )
			{
				prime++;
				printf("%s is incorrect.\n", in);        //// not correct
				an=2;
				
				for(i=0; i<lll; i++)
				{
					in1[i]=in[i]='\0';
					hold[i]=P_sum[i]=0;
				}
				as=1;
			}
			if(as==1)
				break;
		}
		
		if(an==0 && (count!=10 || prime!=10) )
		{
			printf("%s is incorrect.\n", in);          ////// not correct
			an=2;

			for(i=0; i<lll; i++)
			{
				in1[i]=in[i]='\0';
				hold[i]=P_sum[i]=0;
			} 
		}
		
		if(an==0)
		{
			P_sum[0]=hold[0];
			sum=0;
			for(i=0, k=0; i<count; i++)
			{
				sum=hold[i]+P_sum[i-1];
				P_sum[k]=sum;
				k++;
			}
			
			fin=flag=0;
			for(i=0; i<k; i++)
				fin+=P_sum[i];
			
			if(fin%11==0)
				flag=1;
			
			if(flag==1)
			{
				printf("%s is correct.\n", in);

				for(i=0; i<lll; i++)
				{
					in1[i]=in[i]='\0';
					hold[i]=P_sum[i]=0;
				}
			}
			else
			{
				printf("%s is incorrect.\n", in);     /// not correct

				for(i=0; i<lll; i++)
				{
					in1[i]=in[i]='\0';
					hold[i]=P_sum[i]=0;
				}
			}
		}
	}
	return 0;
}

