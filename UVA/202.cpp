#include<stdio.h>
#include<string.h>
#define MAX 100000

long check[MAX];
long after_deci[MAX], before_deci[MAX];

void init(long den)
{
	long i;

	for(i=0; i<den; i++)
	{
		after_deci[i]=before_deci[i]=0;
		check[i]=-1;
	}
	return ;
}

int main()
{
	long den, num, intpart, fractpart, repeat, count,  digit, hold, i, k, j;

	while(scanf("%ld %ld", &num, &den)==2)
	{
		printf("%ld/%ld = ", num, den);
		
		init(den);
		j=0;
		intpart=(num/den);
		fractpart=(num%den);
		before_deci[j++]=intpart;
		

		check[fractpart]=0;
		repeat=-1;
		for(i=0; fractpart; i++)
		{
			fractpart*=10;
			hold=fractpart/den;
			after_deci[i]=hold;

			fractpart%=den;

			if(check[fractpart]==-1)
				check[fractpart]=i+1;
			else
			{
				repeat=check[fractpart];
				i++;
				break;
			}
		}
		digit=i;
		count=digit-repeat;
		if(repeat<0)
		{
			for(i=0; i<j; i++)
				printf("%ld", intpart);

			printf(".");
			for(i=0; i<digit; i++)
				printf("%ld", after_deci[i]);
			
			printf("(0)\n   1 = number of digits in repeating cycle\n\n");
		}
		else
		{
			for(i=0; i<j; i++)
				printf("%ld", before_deci[i]);

			printf(".");
			for(i=0;i<repeat;i++)
				printf("%ld",after_deci[i]);
			
			printf("(");
			for(i=repeat,k=0;i<digit && k<50;i++,k++)
					printf("%ld",after_deci[i]);

		if(i==digit)
			printf(")\n");
		else
			printf("...)\n");
		printf("   %ld = number of digits in repeating cycle\n\n",count);
		}
	}
	return 0;
}
