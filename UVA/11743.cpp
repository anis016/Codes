#include<stdio.h>
#include<string.h>
#define MAX 20

int main()
{
	char in[MAX];
	long n, i;
	long sum1, sum2;

	gets(in);
	sscanf(in, "%ld", &n);

	while(n--)
	{
		gets(in);

		sum1=sum2=0;
		for(i=0; i<19; )
		{
			if(in[i]==' ')
			{
				i++;
				continue;
			}
			
			sum1=sum1+( ((in[i]-'0')*2)%10 + ((in[i]-'0')*2)/10) ;
			sum2=sum2+in[i+1]-'0';
			i=i+2;
		}
		if( ( (sum1+sum2) % 10 ) == 0 )
			printf("Valid\n");
		else
			printf("Invalid\n");
	}

	return 0;
}