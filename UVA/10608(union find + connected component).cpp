#include<stdio.h>
#define MAX 30010

long P[MAX], count[MAX];

long parent(long x)
{
	if(P[x] == -1)
		return x;

	P[x] = parent(P[x]);
	return P[x];
}

int main()
{
	long Case;
	long node, edge, i, t1, t2, x, y, max;

	scanf("%ld", &Case);

	while(Case--)
	{
		scanf("%ld %ld", &node, &edge);
		
		for(i=1; i<=node; i++)
			count[i] = 0, P[i] = -1;

		for(i=0 ;i<edge; i++)
		{
			scanf("%ld %ld", &x, &y);
			t1 = parent(x);
			t2 = parent(y);

			if(t1 != t2)
				P[t1] = t2;
		}

		max = -1;
		for(i=1; i<=node; i++)
			count[parent(i)]++;

		max = -1;
		for(i=1; i<=node; i++)
		{
			if(count[i] > max)
				max = count[i];
		}
		printf("%ld\n", max);
		
	}
	return 0;
}