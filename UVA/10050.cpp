#include<stdio.h>
#define MAX 3670

long hold[MAX];

void blank(void )
{
	hold[0]=1;
	long i;
	for(i=1; i<=3650; )
	{
		i=i+6;
		hold[i-1]=hold[i]=1;
		i++;
	}

}

int main()
{
	long in[MAX];
	long i, j, k, l, t, s;
	long days, count, test;

	blank();

	scanf("%ld", &test);
	while(test--)
	{
		scanf("%ld", &days);		
		scanf("%ld", &t);

		for(i=0; i<t; i++)
		{
			scanf("%ld", &in[i]);
		}
	
		s=0;
		while(s!=t)
		{
			j=0;
			l=1;
			for(i=1; ; )
			{
				j=l*in[s];

				if(j>days)
					break;

				if(hold[j]!=1)
					hold[j]=2;
				l++;
			}
			s++;
		}

		count=0;
		for(k=1; k<=days; k++)
			if(hold[k]==2)
				count++;

		for(k=0; k<=days; k++)
		{
			if(hold[k]!=1)
				hold[k]=0;
		}

		printf("%ld\n", count);
	}
	return 0;
}