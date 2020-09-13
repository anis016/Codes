#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define swap(x, y) x^=y^=x^=y
#define DIV 100000

typedef long LL;

LL N, M, counter, tab[DIV];

struct List
{
	char str[31];
	LL h, c, next;
	LL pst, gst, hst;
} rec[DIV + 200];

int hash(char *s)
{
	unsigned long a;

	for (a = 0; *s;)
		a = ((a << 5) | ((a >> 27) & 31)) ^ (*s++ - 'A');

	return (a % DIV);
}

int sorting(const void *a, const void *b)
{
	List *p = (List *)a;
	List *q = (List *)b;

	return ( strcmp(p->str, q->str) );
}

LL Bsearch(char *s)
{
	LL low, high, mid, f;

	low = 0;
	high = counter - 1;
	while(low <= high)
	{
		mid  = (LL)(low + high) / 2;
		f  = strcmp(s, rec[mid].str);

		if(f > 0)
			low = mid + 1;
		else if(f < 0)
			high = mid -1;
		else if(f == 0)
			return mid;
	}
	return -1;
}

LL reduce_fraction(LL tmp)
{
	if (tmp % 10000 < 5000)
		return tmp / 10000;
	else
		return (tmp / 10000) + 1;
}

void add(char *s, LL pst, LL gst, LL hst)
{
	LL i, h;

	for(i = tab[h = hash(s)]; i >= 0; i = rec[i].next) 
    {
        if(rec[i].h == h && strcmp(rec[i].str, s) == 0) 
        {
          	rec[i].c++;
			rec[i].pst = pst;
			rec[i].gst = gst;
			rec[i].hst = hst;

			return;
		}
    }

	i = counter++;
	strcpy(rec[i].str, s);
	rec[i].h = h;
	rec[i].next = tab[h];
	tab[h] = i;
	rec[i].c = 1;

	rec[i].pst = pst;
	rec[i].gst = gst;
	rec[i].hst = hst;

	return ;
}

LL read_input()
{
	LL i, j, tp, pst, gst, hst;
	char str[DIV], temp;

	for(i = 0; i < N; i++)
	{
		scanf("%s", str);
		
		for(j = 0; j < 3; j++)
		{
			tp = 0;

			scanf("%ld%c", &tp, &temp);
			tp = tp * 100;

			if(temp == '.')
			{
				char next[DIV];
				scanf("%s", next);
				tp += (next[0] - '0') * 10;
				if(next[1] != '%')
					tp += next[1] - '0';
			}
			if(j == 0)
				pst = tp;
			else if(j == 1)
				gst = tp;
			else if(j == 2)
				hst = tp;
		}

		add(str, pst, gst, hst);
	}

	qsort(rec, counter, sizeof(rec[0]), sorting);

	LL sumgp = 0;		
	LL sumh = 0;
	for(i = 0; i < M; i++)
	{
		LL after_deci = 0;
		LL before_deci = 0;

		scanf("%s $%lld.%lld", str, &before_deci, &after_deci);
		LL Tcost = before_deci * 100 + after_deci;

		LL pos = Bsearch(str);
		LL PST = reduce_fraction(rec[pos].pst * Tcost);
		LL GST = reduce_fraction(rec[pos].gst * Tcost);
		sumgp += PST + GST;

		LL HST = reduce_fraction(rec[pos].hst * Tcost);
		sumh += HST;
	}

	LL cost = sumh - sumgp;
	return cost;
}

void init()
{
	LL i;

	counter = 0;
	for (i = 0; i < DIV; i++)
		tab[i] = -1;
	return ;
}

int main()
{
	LL Case;
	
	scanf("%lld", &Case);
	while(Case--)
	{
		init();

		scanf("%lld %lld", &N, &M);
		LL cost = read_input();
		
		if(cost < 0)
		{
			printf("-");
			cost = cost * -1;
		}

		printf("%lld.%02lld\n", cost / 100, cost % 100);
		counter = 0;
	}
	return 0;
}