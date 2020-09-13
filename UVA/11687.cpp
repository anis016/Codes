#include<stdio.h>
#include<string.h>
#define MAX 100000000

char str[MAX];

void convert_len(long a)
{
	long div, mod, i;

	i = 0;
	while(1)
	{
		div = a / 10;
		mod = a % 10;
				
		str[i++] = mod+'0';

		if(div == 0)
			break;
		a = div;
	}
	str[i] = '\0';
	return ;
}

int main()
{
	long len0, count, len1;

	while(scanf("%s", str)==1)
	{
		if(strcmp(str, "1")==0)
		{
			printf("1\n");
			continue;
		}
		if(strcmp(str, "END")==0)
			break;

		count = len0 = len1 = 0;
		while(1)
		{
			len0=strlen(str);
			count++;

			if(len1==len0)
				break;

			convert_len(len0);
			len1=strlen(str);
			count++;
			convert_len(len1);

			if(len1==len0)
				break;
		}
		printf("%ld\n", count);
	}

	return 0;
}

