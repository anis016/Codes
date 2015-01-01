#include<stdio.h>
#include<math.h>

int main()
{
	int test;
	scanf("%d", &test);
	for(int ii = 1; ii <= test; ii++)
	{
		int c, incf;
		scanf("%d %d", &c, &incf);
		printf("Case %d: %.2lf\n", ii, (((( (9.0 / 5.0) * c + 32.0) + (double)incf) - 32.0) * (5.0/9.0) ));
	}
	return 0;
}