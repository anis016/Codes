#include<stdio.h>

int main()
{
	long double m, n, ans;
	while(scanf("%llf %llf", &m, &n)!=EOF)
	{
		ans=(m*n)-1;
		printf("%.0llf\n", ans);
	}
	return 0;
}


