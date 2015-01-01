#include<stdio.h>
#define MAX 200

long table[MAX][MAX];
long N;

long find_submatrix(void )
{
	long max, count, k, i, j, l;

	for(i=1; i<=N*2; i++)
		for(j=1; j<=N*2; j++)
			table[i][j] = table[i][j] + table[i-1][j];       /* Adding row-wise one before the other */

	max = 0;
	
	/*  Algo Part O(n^4)*/

	for(i=1; i<=N; i++) 
	{
		for(j=i; j<i+N; j++) 
		{
			for(k=1; k<=N; k++) 
			{
				count = 0;
				for(l = k; l<k+N; l++) 
				{					
					count += table[j][l] - table[i-1][l];					
					if(count < 0 ) 
						count = 0;
					else if(count>max) 
						max = count;
				}
			}
		}
	}
	return max;
}

void read_case()
{
	long i, j;
	for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
			{
				scanf("%ld", &table[i][j]);
				table[N+i][j] = table[i][j];
				table[i][N+j] = table[i][j];
				table[N+i][N+j] = table[i][j];
			}
	return ;
}

int main()
{
	long res, Case;
	
	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld", &N);

		read_case();		
		
		res=find_submatrix();
		if(res<0)
			printf("0\n");
		else
			printf("%ld\n", res);
	}
	return 0;
}
/*
5
1 -1 0 0 -4
2 3 -2 -3 2
4 1 -1 5 0
3 -2 1 -3 2
-3 2 4 1 -4
*/

