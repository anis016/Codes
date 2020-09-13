#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

#define MAX  101000
char buf[MAX+MAX], buf1[MAX+MAX];

struct List
{
	long fir;
	char sec[100];
}list[MAX];

int sort_function(const void *a, const void *s)
{
	 List *c = (List *)a;
	 List *d = (List *)s;
	 return (c->fir - d->fir);
}

int main()
{
	char *ch, xx[MAX+MAX];
	long kase, N, i;

	gets(xx);
	sscanf(xx, "%ld", &kase);
	gets(xx);
	while(kase--)
	{	
		gets(buf);

		N=0;
		ch=strtok(buf, " ");
		while(ch)
		{
			list[N].fir = atoi(ch);
			ch=strtok(NULL, " ");
			N++;
		}

		gets(buf1);
		
		N=0;
		ch=strtok(buf1, " ");
		while(ch)
		{
			strcpy(list[N].sec, ch);
			ch=strtok(NULL, " ");
			N++;
		}

		qsort( (void *)list, N, sizeof(list[0]), sort_function);

		for(i=0; i<N; i++)
			cout<<list[i].sec<<endl;
			
        if(kase)
           {
                putchar('\n');
                gets(buf);
           }
    }
	return 0;
}
