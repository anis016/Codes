#include<stdio.h>
#define MAX 101

bool v[MAX][MAX]; //visited
char in[MAX][MAX];
long r, c;

void dfs_area(long x,  long y)
{
	long i, j;

	v[x][y] = 1;
	
	for(i=-1; i<=+1; i++)
		for(j=-1; j<=+1; j++)
		{
			bool nelig = (x+i<0 || y+j<0) || (x+i>=r || y+j>=c) ; //not eligible
			if(nelig) continue;

			if(v[x+i][y+j] == 0 && in[x+i][y+j] == '@')
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

int main()
{
	char xx[MAX];
	long i, j;
	long count;

	while(gets(xx))
	{
		sscanf(xx, "%ld %ld", &r, &c);

		if(r==0 && c==0)
			break;
		
		for(i=0; i<r; i++)
			gets(in[i]);

		count=0;
		
		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				if(in[i][j] == '@' && v[i][j] == 0)
				{
					count++;
					dfs_area(i, j);
				}

		printf("%ld\n", count);
		init();
	}

	return 0;
}