#include<stdio.h>

long test, i, j, t;
long in[100000], out[100000];

int main()
{
	while(1)
	{
		scanf("%ld", &test);
		 
		if(test==0)
			break;
		for(i=0; i<test; i++)
		{
			scanf("%ld", &in[i]);
		}

		for(i=0, j=0; i<test; i++)
		{
			if(in[i]==0)
				continue;
			else
			{
				out[j]=in[i];
				j++;
			}
		}
		if(j==0)         //////// critical input
			printf("0\n");
		else
		{
			for(i=0, t=0; i<j; t++, i++)
			{
				printf("%ld", out[i]);
				if(t<j-1)
				{
					printf(" ");
				}
			}
			printf("\n");
		}	
	}
	return 0;
}
