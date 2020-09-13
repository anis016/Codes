#include<stdio.h>
#define MAX 2000

struct graph
{
	char color;
}visit[MAX];

long Q[MAX], QH, QT;
long node, edge;

void push(long n)
{
	Q[QH++] = n;
	QH = QH % MAX;
	return ;
}

long pop()
{
	long top;

	top = Q[QT++];
	QT = QT % MAX;
	return top;
}

long is_empty()
{
	if(QT == QH)
		return 1;
	else
		return 0;
}

long link[MAX][MAX];

long COLORING_BFS(long s)     /// non colored portion is 'g' colored used is 'b' and 'w'
{
	long i, u;
	char ch;

	QH = QT = 0;
	visit[s].color = 'w';
	push(s);
	while(is_empty()==0)
	{
		u = pop();
		ch = 'w';

		if(visit[u].color == 'w')
			ch = 'b';

		for(i=0; i<node; i++)
		{
			if(link[u][i]==1)
			{
				if(visit[i].color == 'g')
				{
					visit[i].color = ch;
					link[u][i] = link[i][u] = 0;
					push(i);
				}
				else if(visit[i].color == visit[u].color)
					return 0;
			}
		}
	}

	return 1;
}

void Process(long sr)
{
	long flag, i;

	for(i=0; i<=node; i++)
		visit[i].color = 'g';

	flag = COLORING_BFS(sr);
	if(flag==1)
		printf("BICOLORABLE.\n");
	else
		printf("NOT BICOLORABLE.\n");

	return ;
}

void init(void )
{
	long i, j;
	for(i=0; i<=node; i++)
		for(j=0; j<=node; j++)
			link[i][j] = 0;
	return ;
}

int main()
{
	long source, x, y;

	while(scanf("%ld", &node), node)
	{
		scanf("%ld", &edge);
		while(edge--)
		{
			scanf("%ld %ld", &x, &y);
			link[x][y] = link[y][x] = 1;
			source = x;
		}
		Process(source);
		init();

		node = 0;
	}
	return 0;
}