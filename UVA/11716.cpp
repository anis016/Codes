#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1000000

int main()
{
	char xx[MAX], in[MAX];
	long n, t, len, i, j, count, d;

	gets(xx);
	sscanf(xx, "%ld",  &n);

	while(n--)
	{
		len=t=0;

		gets(in);
		len=strlen(in);
		
		t=sqrt(len);
		d=0;
		if(t*t == len)
		{
			i=j=0;
			count=0;

			while(1)
			{
				count=0;
				while(1)
				{
					printf("%c", in[i]);
					i=i+t;
					count++;
					d++;

					if(count==t)
						break;
				}
				j=j+1;
				i=j;

				if(d==len)
					break;
			}
		}
		else
		{
			printf("INVALID");
		}

		printf("\n");
	}

	return 0;
}