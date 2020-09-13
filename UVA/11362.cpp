#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 50000

struct List
{
	long count;
	char str[50];
}list[MAX];


int quick_fun(const void *a, const void *b)
{
	if( ((List*)a)->count > ((List*)b)->count )
		return 1;
	else if( ((List*)a)->count < ((List*)b)->count )
		return -1;
	return 0;
}

int main()
{
	char xx[100];
	long n, i, j, len, flag, test;

	gets(xx);
	sscanf(xx, "%ld", &test);

	while(test--)
	{
		cin>>n;
		
		for(i=0; i<n; i++)
		{
			scanf("%s", list[i].str);
			list[i].count=strlen(list[i].str);
		}
		
		qsort(list, n, sizeof(list[0]), quick_fun);

		flag=0;
		for(i=0; i<n; i++)
		{
			len=strlen(list[i].str);
			for(j=i+1; j<n; j++)
			{
				if(strncmp(list[i].str, list[j].str, len)==0)
				{
					printf("NO\n");
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		
		if(flag==0)
			printf("YES\n");
	}
	return 0;
}