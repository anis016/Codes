#include<stdio.h>
#include<stdlib.h>
#define MAX 200

char mat[MAX][MAX], alpha[MAX];
long K, row, col, cnt, count[MAX], index[MAX];
char chart;

long R[] = {-1, 0, 1, 0};
long C[] = {0, 1, 0, -1};

struct List
{
	long alp;  // index
	long count; // value
}list[MAX];

int sort_function( const void *a, const void *b) 
{
   int m =  (( List *)a)->count;
   int n =  (( List *)b)->count;
   
   if(m != n) 
	   return n - m;

   return ((List *)a)->alp - ((List *)b)->alp;
}



void explore(long r, long c)
{
	long i, nr, nc;

	mat[r][c] = 'F';
	for(i=0; i<4; i++)
	{
		nr = r + R[i];
		nc = c + C[i];

		if(nr<0 || nc<0 || nr>row || nc>col)
			continue;

		if(mat[nr][nc] == chart)
		{
			explore(nr, nc);
		}
	}
	return ;
}

void search(long c)
{
	long i, j;
	char ch = char(c);
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			if(ch == mat[i][j])
			{
				count[cnt]++;
				chart = ch;
				explore(i, j);
			}
	return ;
}

void read_input()
{
	long i, j, in;
	
	for(i=97; i<=122; i++)
		alpha[i] = 0;

	for(i=0, K=0; i<row; i++)
		{
			count[i] = 0;
			gets(mat[i]);
			for(j=0; j<col; j++)
			{
				count[j] = 0;
				in = mat[i][j];
				if(!alpha[in])
				{
					index[K++] = mat[i][j];
					in = mat[i][j];
					alpha[in] = mat[i][j];
				}
			}
		}
    return ;
}

int main()
{
//	freopen("10336.txt", "r", stdin);
	char xx[MAX];
	long Case, i, ii;

	gets(xx);
	sscanf(xx, "%ld", &Case);
	for(ii=1; ii<=Case; ii++)
	{
		gets(xx);
		sscanf(xx, "%ld %ld", &row, &col);

		read_input();
		
		i=0;
		for(cnt=0; cnt<K; cnt++)
		{
			search(index[cnt]);
			list[i].count = count[cnt];
			list[i].alp = index[cnt];
			i++;
		}

		qsort( (void *)list, K, sizeof(list[0]), sort_function);
		printf("World #%ld\n", ii);
		for(i=0; i<K; i++)
			printf("%c: %ld\n", char(list[i].alp), list[i].count);

		K = row = col = cnt = 0;
	}
	return 0;
}