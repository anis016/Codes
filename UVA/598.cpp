#include<stdio.h>
#include<string.h>
#define MAX 40

int LB, UB, N;
int flagA, flag;
char paper[MAX][40];

void read_input()
{
	char input[MAX];

	gets(input);
	if(strcmp(input, "*")==0)
	{
		flagA = 1;

		LB = 1;

		N = 0;
		while(gets(paper[N]))
		{
			int len = strlen(paper[N]);
			if(len == 0)
				break;
			N++;
		}

		UB = N;

		return ;
	}

	else
	{
		flag = 0;
		for(int i = 0; input[i]; i++)
			if(input[i] == ' ')
			{
				flag = 2;
				break;
			}

		if(flag == 2)
			sscanf(input, "%ld %ld", &LB, &UB);
		else
		{
			flag = 1;
			sscanf(input, "%ld", &UB);
			LB = 0;
		}

		N = 0;
		while(gets(paper[N]))
		{
			int len = strlen(paper[N]);
			if(len == 0)
				break;
			N++;
		}
		return ;
	}
}

int st[MAX];

void recur(int n, int level, int limit)
{
	st[level] = n;
	if(level == limit)
	{
		int j = st[0];
		printf("%s", paper[j]);

		for(j = 1; j <= level; j++)
			printf(", %s", paper[st[j]]);
		printf("\n");
		return ;
	}

	for(int i = n + 1; i <N; i++)
		recur(i, level + 1, limit);
}

void cal()
{
	int i, j;
	if(flagA == 0 && flag == 1)
	{
		i = UB;
		printf("Size %d\n",i);
		for(j = 0; j <= N - i; j++)
			recur(j, 0, i - 1);
		printf("\n");
	}

	else if(flagA == 0 && flag == 2)
	{
		for(i = LB; i <= UB; i++)
		{
			printf("Size %d\n",i);
			for(j = 0; j <= N - i; j++)
				recur(j, 0, i - 1);
			printf("\n");
		}
	}

	else if(flagA == 1 && flag == 0)
	{
		for(i = LB; i <= UB; i++)
		{
			printf("Size %d\n",i);
			for(j = 0; j <= N - i; j++)
				recur(j, 0, i - 1);
			printf("\n");
		}
	}
}

int main()
{
//	freopen("in.txt", "r", stdin);

	char input[MAX];
	int Case;

	gets(input);
	sscanf(input, "%ld", &Case);
	gets(input);

	while(Case--)
	{
		N = flagA = flag = 0;
		read_input();
		cal();

		if(Case)
			printf("\n");
	}

	return 0;
}