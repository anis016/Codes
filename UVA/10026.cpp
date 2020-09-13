#include<stdio.h>
#include<stdlib.h>
#define MAX 1002

struct List
{
	int Time, Cent, Work;
}store[MAX];

int N;

int sorting(const void *a, const void *b)   // ad > cb as the ratio is a / b > c / d, where item i have cost per day a and take b days to complete, and let item j have cost per day c and take d days to complete.
{
	List *p = ( List *)a;
	List *q = ( List *)b;

	int i = p->Time * q->Cent;  // i day
	int j = q->Time * p->Cent;  // j day 

	if(i != j)
		return i - j;           // j > i
	else
		return p->Work - q->Work;  // j == i
}


int main()
{
	int Case, i;
	
	scanf("%d", &Case);
	while(Case--)
	{
		scanf("%d", &N);
		for(i = 0; i < N; i++)
		{
			scanf("%d %d", &store[i].Time, &store[i].Cent);
			store[i].Work = i + 1;
		}
		
		qsort((void *)store, N, sizeof(store[0]), sorting);

		printf("%d", store[0].Work);
		for(i = 1; i < N; i++)
			printf(" %d", store[i].Work);
		printf("\n");

		if(Case)
			printf("\n");
	}
	return 0;
}