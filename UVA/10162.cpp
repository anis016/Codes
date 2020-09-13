#include<stdio.h>
#include<string.h>

#define MAX 2100
long hold[MAX], N=0;


void find_digit(long n)
{
	long i, k, res, c;

	c = n % 10;

	res = k = c;
	for(i=2; i<=n; i++)
	{
       	res = k * c;
		k = res % 10;
	}
	N += k;
	if(N>=10)
		N = N % 10;

	return ;
}

void pre(void )
{
	long i;

	for(i=1; i<=100; i++)
	{
		find_digit(i);
		hold[i] = N;
	}
	return ;
}

long convert(char *n) 
{
  long i, k= 0, c = 1,sum = 0;
  long l = strlen(n);
  for(i = l-1; i>=0; i--) 
  {
     sum= (n[i] - '0') * c;
     k += sum;
	 c *= 10;
	 if(c == 100) 
		 break;
  }
  return k;	 
}
int main()
{
	char num[MAX];
	long j;

	pre();

	while(scanf("%s", num)==1)
	{
		if(strcmp(num, "0") == 0)
			break;

		j = convert(num);
		printf("%ld\n", hold[j]);
	}

	return 0;
}
