#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef long long tall;

char in[100], in1[100];

int main()
{
	tall ope, num;
	tall len, i, j;
	tall hold[50], temp, sum, max, min, test;
	char *p, op[25];

	scanf("%ld", &test);
	while(test--)
	{
		scanf("%s", in);
		strcpy(in1, in);
		len=strlen(in);
		
		num=0;
		p=strtok(in, "+*");
		while(p!=NULL)
		{
			hold[num]=atol(p);
			p=strtok(NULL, "+*");
			num++;
		}

		for(i=0, ope=0; i<len; i++)
			if(in1[i]=='+' || in1[i]=='*')
			{
				op[ope]=in1[i];
				ope++;
			}

			temp=1;
			sum=1;
			i=0;
			j=0;
			while(j<num)
			{
				sum=hold[j];
				for(i=j; i+1<num; i++)
				{
					if(op[i]=='+')
						sum+=hold[i+1];
					else
						break;
				}
				temp=temp*sum;
				j=i+1;
			}
			max=temp;

			temp=0;
			sum=0;
			i=0;
			j=0;
			while(j<num)
			{
				sum=hold[j];
				for(i=j; i+1<num; i++)
				{
					if(op[i]=='*')
						sum*=hold[i+1];
					else
						break;
				}
				temp=temp+sum;
				j=i+1;
			}
			min=temp;

			printf("The maximum and minimum are %lld and %lld.\n", max, min);
	}
	return 0;
}
