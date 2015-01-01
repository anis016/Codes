#include <stdio.h>

int main()
{
	int R, N, cnum = 0;

	while(scanf("%d %d", &R, &N) && R)
	{
		printf("Case %d: ", ++cnum);
		int s = (R - 1)/N;
		if(s > 26) 
			printf("impossible\n");
		else 
			printf("%d\n", s);
	}
	return 0;
}	
