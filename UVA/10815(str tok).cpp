#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 1000

struct List
{
	char str[1000];
}list[MAX];


int sorting(const void *a, const void *b)
{
	char *s, *t;
	
	s=((struct List*)a)->str;
	t=((struct List*)b)->str;

	return strcmp(s,t);
}

char buf[MAX];
char *delms = " ~!@#$%^&*()_+`1234567890-=[]{}|;\':,.<>/?\\\"\n\t";

int main(void)
{
	char *p, hv[MAX], small[MAX];
	long i, N, j;
	long len;

	N=len=0;
	while(gets(buf))
	{
		p=strtok(buf, delms);
		while(p!=NULL)
		{
			if(p)
			{
				strcpy(hv, p);

				len=strlen(hv);
				for(i=0, j=0; i<len; i++)
				{
					if(hv[i]>='a' && hv[i]<='z')
					{
						small[j]=hv[i];
						j++;
					}
					else 
					{
						small[j]=hv[i]-'A'+'a';
						j++;
					}
				}
				small[j]='\0';

				strcpy(list[N].str, small);
				N++;
			}			
			p=strtok(NULL, delms);
		}
	}
	qsort((void *)list, N, sizeof(list[0]), sorting);

	printf("%s\n", list[0].str);
	for(i=1; i<N; i++)
	{
		if(strcmp(list[i].str, list[i-1].str)==0)
			continue;

		printf("%s\n", list[i].str);
	}
	return 0;
}
