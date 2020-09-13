#include<stdio.h>
#include<string.h>

int main()
{
 char number[10000];
 long int i, line, sum, sum_1, diff, final;
 while(gets(number))
 {
	if(strcmp(number,"0")==0)
		break;
	 else
	 sum=0; sum_1=0; diff=0; final=0;
		line=strlen(number);
		 for(i=0;i<line;i+=2)
		{
			sum+=number[i]-48;
		}
		 for(i=1;i<line;i+=2)
		{
			sum_1+=number[i]-48;
		}
			diff=sum-sum_1;
		if(diff<0)
			final=diff*-1;
		else final=diff;

		if(final%11==0)
			printf("%s is a multiple of 11.\n", number);
		 else
			printf("%s is not a multiple of 11.\n", number);
 }
 return 0;
}
