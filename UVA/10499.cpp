#include<stdio.h>

int main()
{
	long double in, ans;
	long long hold;

	while(scanf("%Lf", &in), in>0)
	{
		if(in==1)                   //////no profit for i peice
			printf("0%%\n");
		else
		{
		   ans=(in/4)*100;            /////area of the sphere=4*area of the circle
		   hold=ans;

		  printf("%lld%%\n", hold);
		}
	}

	return 0;

}