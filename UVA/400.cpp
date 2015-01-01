#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 10000

char mat[MAX][MAX], temp[MAX];
long N, max;

int sort_function(const void *a, const void *b)
{
	return (strcmp ( (char *)a, (char *)b ) );
}

void print_dash()
{
	long i;
	for(i=1; i<=60; i++)
		printf("-");
	printf("\n");
}

void init()
{
	long i, j, len;
	for(i=0; i<N; i++)
	{
		len = strlen(mat[i]);
		for(j=0; j<len; j++)
			mat[i][j] = 0;
	}
	return ;
}

void read_input()
{
	long i, len;
	max = -1;
	for(i=0; i<N; i++)
	{
		scanf("%s", mat[i]);
		len = strlen(mat[i]);

		if(max < len)
		{
			max = len;
			strcpy(temp, mat[i]);
		}
	}
	return ;
}

int main()
{

	long i, col, row, j, k, len, l;

	while(scanf("%ld", &N)==1)
	{
		read_input();

		qsort((void *)mat, N, sizeof(mat[0]), sort_function);

		print_dash();

		col = 62 / (max + 2);
		row = ceil(double(N) / double(col) );

		for(i=0, k=0; i<row; i++)
		{
			k = i;
			for(j=0; j<col; j++)
			{
				if(strcmp(mat[k], "") == 0)
					continue;

				printf("%s", mat[k]);
				len = strlen(mat[k]);

				if(len != 0 && len < 60)
				{
					if(len == max)
						printf("  ");
					else
						for(l=len; l<max + 2; l++)
							printf(" ");
				}
				k = k + row;
			}
			printf("\n");
		}

		init();
	}
	return 0;
}
