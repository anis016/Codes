#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 10000

char list[MAX][MAX];

int sort_function( const void *a, const void *b)
{
   return( strcmp((char *)a,(char *)b) );
}

int main()
{
	long n, i, j, len, flag, test;

	test=1;
	n=0;
	while(scanf("%s", list[n])!=EOF)
	{	
		n++;
		while(1)
		{
			scanf("%s", list[n]);
			if(strcmp(list[n], "9")==0)
				break;
			n++;
		}
		
		qsort((void *)list,n,sizeof(list[0]),sort_function);

		flag=0;
		for(i=0; i<n; i++)
		{
			len=strlen(list[i]);
			for(j=0; j<n; j++)
			{
				if(j==i)
					continue;

				if(strncmp(list[i], list[j], len)==0)
				{
					printf("Set %ld is not immediately decodable\n", test++);
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		
		if(flag==0)
			printf("Set %ld is immediately decodable\n", test++);

		n=0;
	}
	return 0;
}