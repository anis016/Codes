#include<stdio.h>
#include<string.h>

#define MAX 101
#define max 48

long fibo[MAX];
long hold[MAX];

void init_fibo(void)
{
	long i, j, l;

	fibo[0]=0;
	fibo[1]=1;

	for(i=2, j=2; i<=max; i++)
	{
		fibo[j]=fibo[i-1]+fibo[i-2];
		j++;
	}

	for(i=1, l=1; i<j; i++)
	{
		hold[l]=fibo[i]+fibo[i-1];
		l++;
	}
}

int main()
{
	long n, i, pos, len, j, x, k;
	long fibo_in[MAX], flag, test;

	char cypher[MAX], input[MAX], xx[MAX];
	char str[MAX], out[MAX], temp[MAX];
		
	init_fibo();

	gets(xx);
	sscanf(xx, "%ld", &test);

	while(test--)
	{
		for(i=0; i<MAX; i++)
		{
			cypher[i]=str[i]=out[i]=temp[i]=' ';
			fibo_in[i]=0;
		}

		gets(xx);
		sscanf(xx, "%ld", &n);
		
		for(i=1; i<=n; i++)
			scanf("%ld", &fibo_in[i]);
		gets(xx);
		gets(input);
		
		len=strlen(input);
		for(i=0, j=0; i<len; i++)
		{
			if(input[i]>='A' && input[i]<='Z')
				cypher[j]=input[i], j++;
			else
				continue;
		}
		cypher[j]='\0';
		
		flag=0;
		k=0;
		for(i=1; i<=n; i++)
		{
			x=fibo_in[i];
			for(j=1; j<=x; j++)
			{
				if(hold[j]==x)
				{
					pos=j;
					break;
				}
			}
			str[pos]=cypher[k];
			k++;
		}
		
		str[max]='\0';
		i=max-1;

		while(i)
		{
			if(str[i]==' ')
				i--;
			else
				break;
		}
        
        str[i+1] = '\0';
		
		for(j=1; j<=i; j++)
			printf("%c", str[j]);
		printf("\n");

	}
	return 0;
}