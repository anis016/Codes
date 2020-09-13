#include<stdio.h>
#include<string.h>
#define INF 100000

int main()
{
	char in[30], xx[30];
	long i, j, sum, count, len, test, store[30], min;

	while(gets(xx))
	{
		if(strcmp(xx, "0")==0)
			break;

		sscanf(xx, "%ld", &test);

		min=INF;
		j=0;
		while(test--)
		{
			count=0;
			gets(in);
			len=strlen(in);
			for(i=0; i<len; i++)
			{
				if(in[i]==' ')
					count++;
			}
			if(count<min)
				min=count;

			store[j]=count;
			j++;
		}

		sum=0;
		for(i=0; i<j; i++)
		{
			sum+=store[i]-min;
		}
		printf("%ld\n", sum);
	}
	return 0;
}