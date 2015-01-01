#include<stdio.h>
#include<string.h>

#define MAX 20
char buf[MAX], str[MAX];
struct List
{
	int order;
	char temp[20];
}list[MAX];

int main()
{
	int test;
	gets(buf);
	sscanf(buf, "%d", &test);
	for(int ii = 1; ii <= test; ii++)
	{
		int cnt = 0;int len = 0;int maxi = -1;
		while(cnt < 10)
		{
			gets(buf);
			sscanf(buf, "%s %d", str, &len);

			strcpy(list[cnt].temp, str);
			list[cnt].order = len;
			cnt++;

			if(len > maxi)
				maxi = len;
		}

		printf("Case #%d:\n", ii);
		for(int i = 0; i < cnt; i++)
		{
			if(maxi == list[i].order)
				printf("%s\n", list[i].temp);
		}
	}

	return 0;
}