#include<stdio.h>
#include<math.h>

int main()
{
	long double s, d, hold;
	long ans;

	while(scanf("%Lf %Lf", &s, &d)!=EOF)
	{
		hold=0;

		hold=d+( (s*(s-1)/2) );
		ans=ceil((-1+sqrt(1+8*hold))/2);

		printf("%ld\n", ans);
	}

	return 0;
}