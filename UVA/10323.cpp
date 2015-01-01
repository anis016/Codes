#include<stdio.h>

int main()
{
	long in, hold;

	while(scanf("%lld", &in)!=EOF)
	{
		if(in<0)
		{
			if(in%2==0)
				printf("Underflow!\n");
			else
				printf("Overflow!\n");
		}

		else if(in<=7)
			printf("Underflow!\n");
		else if(in>=8 && in<=13)
		{
			if(in==8)
				printf("40320\n");
			else if(in==9)
				printf("362880\n");
			else if(in==10)
				printf("3628800\n");
			else if(in==11)
				printf("39916800\n");
			else if(in==12)
				printf("479001600\n");
			else if(in==13)
				printf("6227020800\n");
		}
		else if(in>13)
			printf("Overflow!\n");
	}

	return 0;
}

