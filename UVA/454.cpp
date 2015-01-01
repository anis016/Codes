#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<cassert>
using namespace std;
#define MAX 500

struct List
{
	char in[MAX];
	char temp[MAX];
}list[MAX];

long remove_space(long n, long len)
{
	long i, j;

	for(i=0, j=0; i<len; i++)
			if(list[n].temp[i]==' ')
				continue;
			else
				list[n].temp[j++]=list[n].temp[i];
	list[n].temp[j]='\0';

	return j;
}

int sort_function(const void *a, const void *s)
{
	 List *c = (List *)a;
	 List *d = (List *)s;

	 return ( strcmp( (char *)c->in, (char *)d->in) );

}
char input[MAX];

int main()
{
//	freopen("454.in", "r", stdin);
	long n, i, j, data, len, len1, Case;

	gets(input);
	sscanf(input,"%ld",&Case);
	gets(input);
	for(data=1; data<=Case; data++)
	{
		
		n=0;
		while(gets(list[n].in))
		{
			if(strlen(list[n].in)==0)
				break;

			strcpy(list[n].temp, list[n].in);

			len=strlen(list[n].temp);
			len1 = remove_space(n, len);
			sort(list[n].temp, list[n].temp+len1);

			n++;
		}

		qsort( (void *)list, n, sizeof(list[0]), sort_function);

		for(i=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				if(strcmp(list[i].temp, list[j].temp)==0)
					printf("%s = %s\n", list[i].in, list[j].in);
			}
		}

		if(data!=Case)
			printf("\n");
	}
	return 0;
}
