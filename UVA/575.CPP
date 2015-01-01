#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char digit_1[100];
    int digit_2[100];
    int i,number,cal;
    long double sum;
    while(gets(digit_1))
    {
		sum=0;
	    if(digit_1[0]=='0')
	    break;
	
	   number=strlen(digit_1);
	   cal=number;
	   for(i=0;i<cal;i++)
	   {
	       digit_2[i]=digit_1[i]-'0';
	       sum+=digit_2[i]*(pow(2,number)-1);
	       number--;
	   }
	   printf("%.0llf\n",sum);
	
    }
    return 0;
}