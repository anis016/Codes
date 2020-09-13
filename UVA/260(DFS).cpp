#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

#define MAX 300

char mat[MAX][MAX], temp[MAX][MAX];
long N;

void init()
{
	long i;
	for(i=0; i<N; i++)
		strcpy(mat[i], temp[i]);
	return ;
}

long R[] = {-1, -1, 0, 0, 1, 1};
long C[] = {-1, 0, -1, 1, 0, 1};

void search(long row, long col)
{
	long i, nr=0, nc=0;

	mat[row][col] = 'F';

	if(col==N-1)
		return ;

	for(i=0; i<6; i++)
	{
		nr = row + R[i];
		nc = col + C[i];

		if(nr<0 || nc<0 || nr>N || nc>N)
			continue;

		if(mat[nr][nc]=='w')
			search(nr, nc);
	}

	return ;
}

int main()
{
	long i, j, count = 1, flag;
	char xx[MAX];

	while(gets(xx))
	{
		sscanf(xx, "%ld", &N);
		if(N==0)
			break;

		for(i=0; i<N; i++)
		{
			gets(mat[i]);
			strcpy(temp[i],mat[i]);
		}

		flag = 0;
		for(i=0; i<N; i++)
		{
			if(mat[i][0]=='w')
			{
				search(i, 0);
				for(j=0; j<N; j++)
				{
					if(mat[j][N-1]=='F')
					{
						printf("%ld W\n", count++);
						flag = 1;
						break;
					}
				}
				if(flag==1)
					break;
				
//				init();
			}
		}
		if(flag==0)
			printf("%ld B\n", count++);
	}
	return 0;
}