#include<stdio.h>
#include<math.h>

int main()
{
	long in, xx;

	while(scanf("%ld", &in), in)
	{
		xx=sqrt(in);
		if(xx*xx==in)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
