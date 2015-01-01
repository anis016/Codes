#include<stdio.h>
#define MAX 50010

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
	long node, edge, i, t1, t2, x, y, max = 1, cnt;

	while(scanf("%ld %ld", &node, &edge)==2)
	{
		if(!node && !edge)
			break;

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

		cnt = 0;
		for(i=1; i<=node; i++)
		{
			count[parent(i)]++;

			if(count[i])
				cnt++;
		}
/*
		cnt = 0;
		for(i=1; i<=node; i++)
		{
			if(count[i] != 0)
				cnt++;
		}
*/
		printf("Case %ld: %ld\n",max++, cnt);
		
	}
	return 0;
}

