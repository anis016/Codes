#include<stdio.h>

int main()
{
	long r, c, Case;
	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld %ld", &r, &c);
		printf("%ld\n", (r/3) * (c/3) );
	}
	return 0;
}
