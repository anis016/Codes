#include<stdio.h>
#define MAX 100000

long r, c, R, C;

long check_r(long row)
{
	if(row<0 || row>R)
		return 1;
	return 0;
}

long check_c(long col)
{
	if(col<0 || col>C)
		return 1;
	return 0;
}

long probR[MAX], probC[MAX];

void init(long r, long c)
{
	long j, k;
	for(j=0; j<R; j++)
	{
		if(r==j)
			probR[j] = 1;
	}
	for(k=0; k<C; k++)
	{
		if(c==k)
			probC[k] = 1;
	}
	return ;
}

int main()
{
	long N, i, flag, row, col, j, count = 0;
	while(scanf("%ld %ld %ld", &R, &C, &N), R, C, N)
	{
		for(i=0; i<N; i++)
		{
			scanf("%ld %ld", &r, &c);
			init(r, c);
		}

		scanf("%ld %ld", &r, &c);
		
		flag = 0;
		while(1)
		{
			row = r;
			col = c;

			if(probR[r]==0 && probC[c] == 0)
			{
				flag = 1;
				break;
			}
			else
			{
				row++;
				if(check_r(row))
				{
					row = r;
				}
				
				if(probR[row]==0 && probC[c] == 0)
				{
					flag = 1;
					break;
				}
				row = r;
				col = c;

				
				row--;
				if(check_r(row))
				{
					row = r;
				}
				
				if(probR[row]==0 && probC[c] == 0)
				{
					flag = 1;
					break;
				}
				row = r;
				col = c;

				col++;
				if(check_c(col))
				{
					col = c;
				}
				
				if(probR[r]==0 && probC[col] == 0)
				{
					flag = 1;
					break;
				}
				row = r;
				col = c;

				
				col--;
				if(check_c(col))
				{
					col = c;
				}
				
				if(probR[r]==0 && probC[col] == 0)
				{
					flag = 1;
					break;
				}
				row = r;
				col = c;
			}
			if(flag==1 || flag==0)
				break;
		}
		if(flag == 1)
		{
			printf("Case %ld: Escaped again! More 2D grid problems!\n", ++count);
		}
		else
			printf("Case %ld: Party time! Let's find a restaurant!\n", ++count);

		for(i=0; i<R; i++)
		{
			probR[i] = 0;
		}
		for(j=0; j<C; j++)
		{
			probC[j] = 0;
		}
	}
	return 0;
}