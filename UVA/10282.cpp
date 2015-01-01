#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100010

struct List
{
	char fir[15];
	char sec[15];
}list[MAX];

int sort_function( const void *a, const void *b)
{
	char *s, *t;

	s = ((struct List*)a)->sec;
	t = ((struct List*)b)->sec;
	return strcmp(s,t);
}

long BSearch(char *s, long N)
{
	long low, high, mid, found;

	low = 0;
	high = N-1;

	while(low<=high)
	{
		mid  = (low+high)/2;

		found  = strcmp(s, list[mid].sec);
		if(found > 0)
			low = mid+1;
		else if(found < 0)
			high = mid-1;
		else
			return mid;
	}
	return -1;
}

int main(void)
{
	char buf[MAX];
	long i, N;

	N = 0;
	while(gets(buf) && buf[0])
	{
		sscanf(buf,"%s %s",list[N].fir, list[N].sec);
		N++;
	}
	
	qsort((void *)list, N, sizeof(list[0]), sort_function);
	
	while(gets(buf) && buf[0])
	{
		i = BSearch(buf, N);

		if(i==-1)
			printf("eh\n");
		else
			printf("%s\n",list[i].fir);
	}
	return 0;
}
