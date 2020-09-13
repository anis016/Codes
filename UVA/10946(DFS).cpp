#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 55
#define MAXL 2500

long R[] = { -1, 0, 0, 1};
long C[] = { 0, -1, 1, 0};

long maxc, maxr, cnt, K;
char mat[MAX][MAX], ch;

struct List
{
	char chart;
	long index;
}list[MAXL+MAX];

int sort_function(const void *a, const void *b)
{
	int m = ((List *)a) ->index;
	int n = ((List *)b) ->index;

	if(m!=n)
		return n - m;

	int p = ((List *)a) ->chart; 
	int q = ((List *)b) ->chart;

	return p - q;
}

void search(long row, long col)
{
	long i, nr, nc;
	
	if(mat[row][col] == ch)
		cnt++;

	mat[row][col] = '.';
	for(i=0; i<4; i++)
	{
		nr = R[i] + row;
		nc = C[i] + col;

		if(mat[nr][nc] == ch)
			search(nr, nc);
	}
	return ;
}

void process(void )
{
	long i, j;

	K = 0;
	for(i=0; i<maxr; i++)
		for(j=0; j<maxc; j++)
			if(mat[i][j] != '.')
			{
				ch = mat[i][j];
				cnt = 0;
				search(i, j);
				list[K].chart = ch;
				list[K].index = cnt;
				K++;
			}
	return ;
}


int main()
{
	long i, c = 1;
//	freopen("in.txt", "r", stdin);

	while(scanf("%ld %ld", &maxr, &maxc)==2)
	{
		if(!maxr && !maxc)
			break;

		K = 0;
		getchar();
		for(i=0; i<maxr; i++)
			gets(mat[i]);
		
		process();

		qsort( (void *)list, K, sizeof(list[0]), sort_function);

		printf("Problem %ld:\n", c++);
		for(i=0; i<K; i++)
			printf("%c %ld\n", list[i].chart, list[i].index);
	}

	return 0;
}