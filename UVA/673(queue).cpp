#include<stdio.h>
#include<string.h>
#define MAX 129

struct queue
{
	char par[MAX];
	long front, rear;
}Q;

void init(void )
{
	long i;

//	for(i=0; i<MAX; i++)
//	{
//		Q.par[i]=NULL;
//	}
	Q.rear=0;
	Q.front=0;

	return ;
}

void pop(queue *q)
{
	q->par[q->front++];
	q->par[q->rear--] = 0;
}

void push(queue *q, char x)
{
	if(q->rear == MAX-1)
		q->rear = 0;
	else
		q->rear++;

	q->par[q->rear] = x;

	return ;
}

char top(queue *q)
{
	return q->par[q->rear];
}

char str[MAX];

int main()
{
	long len, i, flag, Case;
	char t, xx[MAX];

	gets(xx);
	sscanf(xx, "%ld", &Case);
	while(Case--)
	{
	//	init();
		Q.front = Q.rear = 0;

		gets(str);
		len=strlen(str);

		flag=0;
		for(i=0; i<len; i++)
		{
			if(str[i] == '(' || str[i] == '[')
				push(&Q, str[i]);
			else if(str[i] == ']' || str[i] == ')')
			{
				t = top(&Q);
				push(&Q, str[i]);
				if( (str[i] == ']' && t == '[') || (str[i] == ')' && t == '(') )
				{
					pop(&Q);
					pop(&Q);
				}
				else
					flag = 1;
			}

			if(flag==1)
				break;
		}

		if(Q.front == len && Q.rear == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}