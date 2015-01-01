#include<stdio.h>
#include<string.h>
#define MAX 100000

long P[MAX];
long node, t1, t2;
char buf[MAX];

long parent(long x)
{
	if(P[x] == -1)
		return x;

	P[x] = parent(P[x]);

	return P[x];
}

void init()
{
	long i;

	for(i=1; i<=node; i++)
		P[i] = -1;

	return ;
}

void make_connection(long x, long y)
{
	t1 = parent(x);
	t2 = parent(y);

	if(t1 != t2)
		P[t1] = t2;
	return ;
}

bool check_connection(long x, long y)
{
	t1 = parent(x);
	t2 = parent(y);
	
	if(t1 != t2)
		return false;
	return true;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	long cnt_n, cnt_y, x, y, Case;
	char ch;
	bool flag;

	scanf("%ld", &Case);
	getchar();
	while(Case--)
	{
		scanf("%ld", &node);
		getchar();

		init();

		cnt_n = cnt_y = 0;
		while(gets(buf))
		{
			if(strlen(buf) == 0)
				break;

			sscanf(buf, "%c %ld %ld", &ch, &x, &y);
			
			if(ch == 'c')
			{
				make_connection(x, y);
			}	
			else
			{
				flag = check_connection(x, y);
				if(flag == false)
					cnt_n++;
				else
					cnt_y++;
			}
		}

		printf("%ld,%ld\n", cnt_y, cnt_n);

		if(Case)
			printf("\n");
	}
	return 0;
}
