#include<stdio.h>

int main()
{
	int N;

	while(scanf("%d", &N)==1)
	{
		if(!N)
			break;
		printf("%d\n", N >> 1);
	}
	return 0;
}