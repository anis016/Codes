#include<stdio.h>
#include<string.h>
#define MAX 10000

char in[MAX];
long check[10010];

void init(void )
{
	long i;

	for(i=0; i<=9999; i++)
		check[i] = 0;
	return ;
}

void remove_zero(void )
{
	long i, len, j, flag;

	len = strlen(in);

	flag=0;
	for(i=0, j=0; i<len; i++)
	{
		if(in[i]=='0' && flag==0)
		{
			continue;
		}
		else
		{
			in[j++] = in[i];
			flag=1;
		}
	}
	in[j]='\0';
	return ;
}

long convert(void )
{
	long i, len, j, sum;

	len = strlen(in);

	j=1;
	for(i=1; i<len; i++)
		j = j*10;

	sum=0;
	for(i=0; i<len; i++, j/=10)
		sum += j * (in[i] - '0');

	return sum;
}

void form_str(long sq, char x[10])
{
	long i, j, t;

	j = 7;
	x[j+1] = '\0';
	for(i=0; ;)
	{
		if(j<0)
			break;
		t = sq % 10;
		sq = sq / 10;
		x[j] = t + '0';
		j--;
	}
}

void take_middle(char temp[])
{
	long len = strlen(temp);
	long i, j;

	for(i=2, j=0; i<(len-2); i++)
	{
		in[j]=temp[i];
		j++;
	}
	in[j]='\0';
	return ;
}


int main()
{
	char temp[100];
	long k, sq, count;

	while(scanf("%s", in)==1)
	{
		if(strcmp(in, "0")==0)
			break;

		count=0;
		while(1)
		{
			remove_zero();
			k = convert();

			if(check[k]==0)
			{
				check[k] = 1;
				count++;
				sq = k * k;
				form_str(sq, temp);
				take_middle(temp);
			}
			else
			{
				break;
			}
		}
		
		printf("%ld\n", count);
		init();
	}

	return 0;
}