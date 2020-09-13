#include<stdio.h>
#include<string.h>
#define MAX 1000
#define INF -99999999

struct List
{
	char str[35];
	long index;
}buff[MAX];

long mat[MAX][MAX];

long node;
long vertex, edge; 
char source[35], destination[35];
char t_s[35], t_d[35];

long min(long a, long b)
{
	if(a > b)
		return b;
	else
		return a;
}

long max(long a, long b)
{
	if(a > b)
		return a;
	else
		return b;
}

void init()
{
	long i, j;

	for(i=1; i<=vertex; i++)
		for(j=1; j<=vertex; j++)
			if( i == j)
				mat[i][j] = 0;
			else
				mat[i][j] = INF;

	return ;
}

void read_input()
{
	long wt;
	long xx, xy, i, flag, sx, sy, ii;

	node = 1;
	for(ii=0; ii<edge; ii++)
	{
		scanf("%s %s %ld", t_s, t_d, &wt);

		flag = sx = sy = 0;
		for(i=1; i<node; i++)
		{
			if(strcmp(buff[i].str, t_s)==0)
			{
				xx = i;
				buff[node].index = xx;
				sx = 1;
			}
			if(strcmp(buff[i].str, t_d)==0)
			{
				xy = i;
				buff[node].index = xy;
				sy = 1;
			}
		}
		
		if(sx == 0)
		{
			strcpy(buff[node].str, t_s);
			xx = node;
			buff[node].index = xx;
			node++;
		}
		if(sy == 0)
		{
			strcpy(buff[node].str, t_d);
			xy = node;
			buff[node].index = xy;
			node++;
		}

		mat[xx][xy] = mat[xy][xx] = wt;
	}
	
	node = node - 1;

	return;
}

void warshall(void )
{
	long i, j, k;

	 for(k = 1 ; k <= node; ++k)
		 for(i = 1 ; i <= node; ++i)
			 for(j = 1 ; j <= node; ++j)
				 mat[i][j] = max( mat[i][j], min(mat[i][k], mat[k][j]) ); 
	return ;
}

long search(char *in)
{
	long i;

	for(i=1; i<=node; i++)
		if( strcmp(buff[i].str, in)==0 )
			return buff[i].index;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	long sr, dest, weight, cnt = 1;	
	
	while(scanf("%ld %ld", &vertex, &edge)==2)
	{
		if(!vertex && !edge)
			break;
		
		init();
		read_input();

		scanf("%s %s", source, destination);

		sr = search(source);
		dest = search(destination);

		warshall();

		weight = mat[sr][dest];
		
		printf("Scenario #%ld\n", cnt++);
		printf("%ld tons\n", weight);
		printf("\n");
	}

	return 0;
}