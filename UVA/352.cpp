#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 26

bool v[MAX][MAX]; //visited
long A[MAX][MAX];
long r, c;

void dfs_area(long x, long y)
{
	long i, j;

	v[x][y] = 1;
	
	for(i=-1; i<=+1; i++)
		for(j=-1; j<=+1; j++)
		{
			bool nelig = (x+i<0 || y+j<0) || (x+i>=r || y+j>=c) ; //not eligible
			if(nelig)
				continue;

			if(v[x+i][y+j] == 0 && A[x+i][y+j] == 1)
			{
				dfs_area(x+i, y+j);
			}
		}
}

void init(void)
{
	long i, j;

	for(i=0; i<=r; i++)
		for(j=0; j<=c; j++)
			v[i][j]=false;
}

void read_case(char *n, long len, long k)
{
	long i, j;
	len = strlen(n);

	for(i=0; i<len; i++)
	{
		j = n[i] - '0';
		A[k][i] = j;
	}
	return ;
}

int main()
{
	char xx[MAX];
	long i, j, len, num=0;
	long count;
	long Case, s;

	while(gets(xx))
	{
		sscanf(xx, "%ld", &Case);
		c = s = r = 0;
		while(Case--)
		{
			gets(xx);
			if(strcmp(xx, "")==0)
				break;
			len=strlen(xx);
			s = r++;
			read_case(xx, len, s);
		}

		c = len;
		count=0;
		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				if(A[i][j] == 1 && v[i][j] == 0)
				{
					count++;
					dfs_area(i, j);
				}

		printf("Image number %ld contains %ld war eagles.\n", ++num, count);
		init();
	}

	return 0;
}
