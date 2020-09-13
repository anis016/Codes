#include<stdio.h>
#define MAX 501
#define swap(xxx, yyy) xxx^=yyy^=xxx^=yyy

long mat[MAX][MAX];
long W, H, N, x1, y1, x2, y2, i, j, k, count;

void init()
{
	long i, j;
	for(i=1; i<=W; i++)
	{
		for(j=1; j<=H; j++)
			mat[i][j] = 1;
		
	}
	return ;
}

void output()
{
	long i, j;

	for(i=1; i<=W; i++)
	{
		for(j=1; j<=H; j++)
			if(mat[i][j] == 1)
			 count ++;
	}
	return ;
}

int main()
{
	while(scanf("%ld %ld %ld", &W, &H, &N)==3)
	{
		if(!W && !H && !N)
			break;

		init();
		for(k=1; k<=N; k++)
		{
			scanf("%ld %ld %ld %ld", &x1, &y1, &x2, &y2);
			if(x1 > x2)
				swap(x1, x2);
			if(y1 > y2)
				swap(y1, y2);

			for(i=x1; i<=x2; i++)
				for(j=y1; j<=y2; j++)
					mat[i][j] = 0;

		}
		count = 0;
		output();

		if(N==0)
		{
			count = W * H;
			printf("There are %ld empty spots.\n", count);
		}

		else if(count==0)
			printf("There is no empty spots.\n");
		else if(count==1)
			printf("There is one empty spot.\n");
		else
			printf("There are %ld empty spots.\n", count);

		count = 0;
	}

	return 0;
}