#include<stdio.h>

int main () 
{
	int ii = 1;

	int test;
	scanf("%d", &test);
	while(test--)
	{
		int store;
		int i, n, p, q;
		scanf("%d %d %d", &n, &p, &q);
		int cnt = 0; int j; int flag = 0; int sum = 0;
		for(j = 0, i = 0; i < n; i++)
		{
			scanf("%d", &store);
			sum+=store;
			j++;
			if(sum > q || j > p)
				flag = 1;
			if(flag == 0)
				cnt++;
		}
		printf("Case %d: %d\n", ii++, cnt);
   }
   return 0;
}
