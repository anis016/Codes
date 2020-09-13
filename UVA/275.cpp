#include<stdio.h>
#include<string.h>
#define MAX 1000000

long check[MAX];
char after_deci[MAX];

void init(long den)
{
	long i;

	for(i=0; i<den; i++)
	{
		after_deci[i]='\0';
		check[i]=-1;
	}
	return ;
}

int main()
{
	long den, flag=0, num, fractpart, repeat, count, count1, digit, hold, i, j;

	while(scanf("%ld %ld", &num, &den)==2)
	{
		if(num==0 && den==0)
			break;

		init(den);

		fractpart=(num%den);
		check[fractpart]=0;
		repeat=-1;
		after_deci[0]='.';
		for(i=0, j=1; fractpart; j++, i++)
		{
			fractpart*=10;
			hold=fractpart/den;
			after_deci[j]=hold+'0';

			fractpart%=den;

			if(check[fractpart]==-1)
				check[fractpart]=i+1;
			else
			{
				repeat=check[fractpart];
				i++;
				j++;
				break;
			}
		}
		digit=i;
		count1=digit-repeat;
		if(repeat<0)
		{
			if(digit==0)
			{
				printf(".0");
				printf("\n");
				printf("This expansion terminates.\n\n");
			}
			else
			{
				for(i=0, count=0; i<j; count++, i++)
				{
					if(count==50)
					{
						printf("\n");
						count=0;
					}
					printf("%c", after_deci[i]);
				}
				printf("\n");

				printf("This expansion terminates.\n\n");
			}
		}
		else
		{
			for(i=0, count=0;i<j;count++, i++)
			{
					if(count==50)
					{
						printf("\n");
						count=0;
					}
					printf("%c", after_deci[i]);
			}
			printf("\n");

			printf("The last %ld digits repeat forever.\n\n",count1);
		}
	}
	return 0;
}
