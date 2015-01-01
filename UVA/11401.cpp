#include<stdio.h>
#define MAX 1000010

typedef long long Long;

Long store[MAX];

void load_triangle()
{
	Long b,  n, R;

	store[3] = 0;
	store[4] = 1;

	for(n=5; n<=1000000; ++n)
	{
		b = n/2+1;
		R = n*(n-1)-(n+1)*(n-b)-b*(b-1);
		store[n] = store[n-1] + R;
	}

	return ;
}

int main()
{
	Long n;
	
	load_triangle();
	while(scanf("%lld", &n))
	{
		if(n<3)
			break;
		else
		{
			printf("%lld\n", store[n]);
		}
	}
	
	return 0;
}