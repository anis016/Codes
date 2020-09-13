#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAX 1000

struct List
{
	char str[10];
	char sstr[10];
}list[MAX];

int sort_function(const void *a, const void *s)
{
	 List *c = (List *)a;
	 List *d = (List *)s;

	 return ( strcmp( (char *)c->str, (char *)d->str) );

}

int main()
{
	char xx[MAX];
	long n, len, i, flag;

	n = 0;
	while(gets(xx))
	{
		if(strcmp(xx, "XXXXXX")==0)
			break;
		len = strlen(xx);
		strcpy(list[n].str, xx);

		sort(xx, xx+len);
		strcpy(list[n].sstr, xx);
		n++;
	}
	qsort( (void *)list, n, sizeof(list[0]), sort_function);

	while(gets(xx))
	{
		if(strcmp(xx, "XXXXXX")==0)
			break;

		len = strlen(xx);
		sort(xx, xx+len);

		flag = 0;
		for(i=0; i<n; i++)
		{
			if(strcmp(xx, list[i].sstr)==0)
			{
				printf("%s\n", list[i].str);
				flag = 1;
			}
		}
		if(flag == 0)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}

	return 0;
}