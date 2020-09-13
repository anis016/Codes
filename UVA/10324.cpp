#include<stdio.h>
#include<string.h>
#define MAX 1000010

long count[MAX];

int main()
{
	char store[MAX];
	long i, j, ii, jj, len, test, inc;

	inc=1;
	while(scanf("%s", store)==1)
	{
		len=strlen(store);
		count[0]=0;
		j=0;
		for(i=1; i<len; i++)
		{
			if(store[i-1]!=store[i])
				count[i]=++j;
			else
				count[i]=j;
		}
		scanf("%ld", &test);
		printf("Case %ld:\n", inc++);
		for(i=0; i<test; i++)
		{
			scanf("%ld %ld", &ii, &jj);
			if(count[ii]==count[jj])
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}