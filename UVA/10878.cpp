#include<cstdio>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

long todeci(char *S1)
{
	long len=strlen(S1);
	long i, sum=0, j=0;

	for(i=len-1; i>=0; i--)
		sum+= ( (S1[i]-'0') * long((pow(2, j++))) );
	return sum;
}

char in[100], line[100], hold[100];

int main()
{
	long dec;
    long i, j, flag;
	
	cin.getline(line, 20, '\n');
	
	i=0;
	while(1)
	{
		dec=flag=0;
		cin.getline(in, 20, '\n');
		
		if(strcmp(line, in)==0)
			break;
		
		for(i=0, j=0; i<13; i++)
		{
			if(in[i]=='o')
			{
				hold[j]='1';
				j++;
				flag=1;
			}
			else if(in[i]==' ' && flag==1)
			{
				hold[j]='0';
				j++;
			}
		}
		hold[j]='\0';
		dec=todeci(hold);
		cout<<char(dec);
	}
	return 0;
}