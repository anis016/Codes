#include<stdio.h>

#define MAX 1001
long n;

struct stack
{
	long value[MAX];
	long pos;

}st;

stack S, T;

void init(stack *s)
{
	long i;

	for(i=0; i<=n; i++)
		s->value[i]=-1;
	s->pos=1;
}

void push(stack *s, long val)
{
	s->value[s->pos]=val;
	s->pos++;
	return ;
}

void pop(stack *s)
{
	s->pos--;
	s->value[s->pos]=-1;
}

long top(stack *s)
{
	long temp = s->value[s->pos-1];
	return temp;
}

void inita()
{
	long i;
	for(i=1; i<=n;i++)
	{
		init(&S);
		init(&T);
	}

}

int main()
{
//	freopen("514.in", "r", stdin);
//	freopen("514.out", "w", stdout);

	long x, i,  tempS, flag, tempT, D[MAX];

	while(1)
	{
		scanf("%ld", &n);
		if(n==0)
			break;

		for(i=1; i<=n; i++)
				scanf("%ld", &D[i]);

		while(1)
		{			
			inita();

			for(i=n; i>=1;i--)
				push(&S, i);

			flag=0;
			for(i=1; i<=n; i++)
			{
				x=D[i];
				tempT=top(&T);

				if(x!=tempT && S.pos==1)
					break;

				if(tempT!=x)
				{
					while(tempT!=x)
					{
						if(S.pos==1)
						{
							flag=1;
							break;
						}
						
						tempS=top(&S);
						if(tempS==x)
						{
							D[i]=-1;
							pop(&S);
							break;
						}
						else
						{
							push(&T, tempS);
							pop(&S);
						}
					}
				}

				if(tempT==x)
				{
					pop(&T);
					D[i]=-1;
					continue;
				}
			}

			if(S.pos == 1 && T.pos == 1)
				printf("Yes\n");
			else
				printf("No\n");

			scanf("%ld", &D[1]);
			if(D[1]==0)
			{
				printf("\n");
				break;
			}
			else
				for(i=2; i<=n; i++)
					scanf("%ld", &D[i]);
		}
	}

	return 0;
}