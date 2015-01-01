#include<stdio.h>
#include<string.h>
#define MAX 5000

typedef struct
{
	long var[MAX];
	long front;
	long rear;
}queue;

struct List
{
	char str[20];
}buff[MAX];

long link[MAX][MAX];
long path[MAX], visit[MAX], edge, node, list[MAX];

void init_queue(queue *q)
{
	long i;
	for(i=1; i<=node; i++)
	{
		q->var[i] = -1;
		path[i] = i;
		visit[i]= 0;
	}
	q->front = q->rear = 0;
	return ;
}

void push(queue *q, long item)
{
	q->var[q->rear+1] = item;
	q->rear++;

	return ;
}

void pop(queue *q)
{
	q->var[q->front] = -1;
	q->front++;
	return ;
}

long top(queue *q)
{
	long temp;
	temp = q->var[q->front+1];
	return temp;
}

bool is_empty(queue *q)
{
	if(q->rear == q->front)
		return true;
	return false;
}

long ss = 0;
void PrintPath(int n) 
{
	if(n == path[n]) 
    {
		list[ss++] = n;
		return;
	}
	PrintPath(path[n]);
	list[ss++] = n;
}

long BFS_QUEUE(long sr, long dest)
{
	queue q;
	long t, i, k=0;

	init_queue(&q);
	visit[sr] = 1;
	push(&q, sr);

	while(is_empty(&q) == false)
	{
		t = top(&q);
		pop(&q);
		visit[t] = 1;

		if(t == dest)
		{
			PrintPath(t);
			break;
		}

		for(i=1; i<=node; i++)
		{
			if(link[t][i]==1 && visit[i]==0)
			{
				visit[i] = 1;
				push(&q, i);
				path[i] = t;
			}
		}
	}
	return -1;
}

void read_case(long t)
{
	long xx, xy, n, i, j, flag, sx, sy;
	char x[100], y[100];

	edge = t;
	flag = n = i = 0;
	j = 1;
	node = 1;
	while(edge--)
	{
		scanf("%s %s", x, y);

		flag = sx = sy = 0;
		for(i=1; i<node; i++)
		{
			if(strcmp(buff[i].str, x)==0)
			{
				xx = i;
				sx = 1;
			}
			if(strcmp(buff[i].str, y)==0)
			{
				xy = i;
				sy = 1;
			}
		}
		
		if(sx == 0)
		{
			strcpy(buff[node].str, x);
			xx = node;
			node++;
		}
		if(sy == 0)
		{
			strcpy(buff[node].str, y);
			xy = node;
			node++;
		}
		
		link[xx][xy] = link[xy][xx] = 1;
	}
	return ;
}

void convert_source(char *x, char *y)
{
	long i, xx, xy, flag1=0, flag2=0;
	for(i=1; i<node; i++)
	{
		if(strcmp(buff[i].str, x)==0)
		{
			xx = i;
			flag1 = 1;
		}
		if(strcmp(buff[i].str, y)==0)
		{
			xy = i;
			flag2 = 1;
		}
	}
	if(flag1 == 1 && flag2 == 1)
	{
		node = node-1;
		BFS_QUEUE(xx, xy);
		return ;
	}
	else
		return ;
}

void init(void )
{
	long i, j;
	for(i=0; i<=node; i++)
		for(j=0; j<=node; j++)
			link[i][j] = 0;
}

int main()
{
//	freopen("762i.txt", "r", stdin);
//	freopen("762o.txt", "w", stdout);
	long i, Case, flag = 0;
	char sr[MAX], dest[MAX];

	while(scanf("%ld", &Case)==1)
	{
		if(flag == 1)
			printf("\n");
		flag = 1;

		read_case(Case);
		scanf("%s %s", sr, dest);
		convert_source(sr, dest);
		
		if(ss)
		{
			for(i=0; i<(ss-1); i++)
			{
				printf("%s %s\n", buff[list[i]].str, buff[list[i+1]].str);
			}
			ss=0;
		}
		else
			printf("No route\n");

		init();
		node = 0;
	}	
	return 0;
}
