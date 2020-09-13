#include<stdio.h>

int main()
{
	long long n, i, count=0, hold=0;
	long double ans=0;
 
	while(scanf("%lld", &n)!=EOF)
	{
		ans=count=hold=0;

		if(n%2==1 )
		{
			hold = (n+1)/2;

			count=0;
			for(i=0; i<=hold; i=i+1)
				count+=i;
			
			ans=count;
			
			printf("%.0Lf\n", ans);
		}
		else if(n%2==0)
		{
			hold = (n/2)+1;

			count=0;
			for(i=0; i<=hold; i=i+1)
				count+=i;
			
			ans=count;
			
			printf("%.0Lf\n", ans);
		}
	}

	return 0;
}