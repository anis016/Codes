#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 15010

struct List
{
	char buf[40];
	long vertex;
}list[MAX];

char xx[MAX], buf1[MAX], buf2[MAX];
long node, count[MAX], P[MAX];

int sort_function(const void *a, const void *s)
{
	 List *c = (List *)a;
	 List *d = (List *)s;

	 return ( strcmp(c->buf, d->buf) );
}

long search(char *s)
{
	int l,h,m,f;

	l = 0;
	h = node - 1;
	while(l<=h)
	{
		m  = (l+h)/2;

		f  = strcmp(s,list[m].buf);
		if(f > 0)
			l = m+1;
		else if(f < 0)
			h = m-1;
		else
			return list[m].vertex;
	}
	return -1;
}

void init()
{
	long i;

	for(i=0; i<=node; i++)
	{
		count[i] = 0;
		P[i] = -1;
	}
}

long parent(long x)
{
	if(P[x]==-1)
		return x;
	
	P[x] = parent(P[x]);
	
	return P[x];
}

int main()
{
	long M, i, x, y, t1, t2, maxi;

	while(scanf("%ld %ld", &node, &M) == 2 )
	{
		if(!node && !M)
			break;

		for(i=0; i<node; i++)
		{
			scanf("%s", list[i].buf);
			list[i].vertex = i + 1;
		}
		
		qsort( (void *)list, node, sizeof(list[0]), sort_function);

		init();

		for(i=0; i<M; i++)
		{
			scanf("%s %s", buf1, buf2);
			x = search(buf1);
			y = search(buf2);

			t1 = parent(x);
			t2 = parent(y);

			if(t1!=t2)
				P[t1]=t2;
		}

		for(i=1;i<=node;i++)
			count[parent(i)]++;

		maxi = -1;
		for(i=1; i<=node; i++)
			if(count[i] > maxi)
				maxi = count[i];

		if(maxi <= 0)
			maxi = 1;

		printf("%ld\n", maxi);
	}
	
	return 0;
}
