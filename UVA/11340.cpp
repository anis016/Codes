#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

#define MAX 200000
long penc[MAX], hold[MAX];

int main()
{
	char xx[MAX], buf[MAX], ch[MAX];
	long i, j, k, sen_len, len, kase, cha_num, sum, ii;
	double value;

	gets(xx);
	sscanf(xx, "%ld", &kase);
	while(kase--)
	{
		gets(xx);
		sscanf(xx, "%ld", &cha_num);

		for(i=0; i<cha_num; i++)
		{
			gets(xx);
			sscanf(xx, "%c %ld", &ch[i], &penc[i]);
		}
		ch[cha_num]='\0';

		gets(xx);
		sscanf(xx, "%ld", &sen_len);

		sum=0;
		value=0;
		for(i=0; i<sen_len; i++)
		{
			strcpy(buf, "\0"); 
			len=0;

			gets(buf);
			len=strlen(buf);
			
			for(ii=0; ii<129; ii++)
				hold[ii]=0;
			
			for(j=0; j<len; j++)
				hold[buf[j]]++;

			sum=0;
			for(k=0; k<cha_num; k++)
			{
				sum+=hold[ch[k]]*penc[k];
			}
			value+=sum/100.0;
		}
		printf("%.2lf$\n", value);
	}

	return 0;
}