#include<stdio.h>
#include<stdlib.h>

#define MAX 1001

struct List
{
	long weight;
	long iq;
	long index;
}list[MAX];

long N;
long K = 0;

long pred[MAX];
long length[MAX];
long store[MAX];

int sort_function(const void *a, const void *b)
{
	int m =  (( List *)a)->iq;
	int n =  (( List *)b)->iq;
   
   if(m != n) 
	   return n - m;

   return ((List *)a)->iq - ((List *)b)->iq;
}

void path(long n)
{
	if(pred[n] == -1)
	{
		store[K++] = list[n].index;
		return ;
	}
	store[K++] = list[n].index;
	path(pred[n]);
}


void LIS()
{
	long i, j;
	
	for(i = 1; i < N; i++)
		for(j = 0; j < i; j++)
		{
			if(list[i].weight > list[j].weight && length[j] + 1 > length[i])
			{
				length[i] = length[j] + 1;
				pred[i] = j;
			}
		}

   long max = 0;
   long index = 0;

   for(i = 0; i < N; i++)
   {
	   if(length[i] > max)
	   {
		   max = length[i];
		   index = i;
	   }
   }

   path(index);

   printf("%ld\n", K);
   for(i = K - 1; i>=0; i--)
	   printf("%ld\n", store[i]);
}

int main()
{
//	freopen("in.txt", "r", stdin);

	long i = 0;
	while(scanf("%ld %ld", &list[i].weight, &list[i].iq)==2)
	{
		pred[i] = -1;
		length[i] = 1;
		store[i] = -1;

		list[i].index = i + 1;

		i++;
	}
	N = i;
	
	qsort((void*)list, N, sizeof(list[0]), sort_function);
	
	LIS();

	return 0;
}