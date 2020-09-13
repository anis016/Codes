#include<stdio.h>
#define MAX 30500

long test;
double a_init, a_last, c[MAX], sum;
long i, j, k;

int main()
{
	long n, j, flag=0;
	double res, a1;
	scanf("%ld",  &test);

	while(test--)
	{
		scanf("%ld", &n);
		scanf("%lf", &a_init);
		scanf("%lf", &a_last);

		for(i=1; i<=n; i++)
		{
			scanf("%lf", &c[i]);
		}

		res=sum=0.0;
		for(i=1, j=0; i<=n; i++)
		{
			sum=sum+(n-j)*c[i];
			j++;
		}

		sum=sum*2.0;
		res=n*a_init + a_last - sum;
		a1=res/double(n+1.0);

		if(flag==1)
			printf("\n");
		else 
			flag=1;
		
		printf("%.2lf\n", a1);

		n=res=a1=a_init=a_last=sum=0.0;
	}
	
	return 0;
}