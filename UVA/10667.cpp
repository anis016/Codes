#include<stdio.h>
#define MAX 1000
#define INFINITY -100001

long table[MAX][MAX];
long N;

void init(void )
{
	long i, j;

	for(i=0; i<=N; i++)
		for(j=0; j<=N; j++)
			table[i][j]=1;

	return ;
}

void find_submatrix(void )
{
	long max, count, k, diff, i, j;
	
	if(N==1)          //  critical case.........
	{ 
		if(table[N][N-1]<0) 
			printf("0\n");
		else 
			printf("1\n");

		return;
   }
	
   for(i=1; i<=N; i++)
  	  for(j=0; j<N; j++)
	 	table[i][j] = table[i][j] + table[i-1][j];       /* Adding row-wise one before the other */

	max = table[1][0];
	for(k=1; k<=N; k++)
		for(i=0; i<=(N-k); i++)
		{					
			count=0;			
			for(j=0; j<N; j++)
			{
				diff = table[i+k][j] - table[i][j];
				if(count>=0)
					count+= diff;
				else
					count = diff;

				if(count>max)
					max=count;
			}
		}

		if(max <= 0) 
			printf("0\n");
		else
			printf("%ld\n",max);
}

int main()
{
//	freopen("in.txt", "r", stdin);
	long i, j, k, Case;
	long r1, c1, r2, c2, num;
	
	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld", &N);
		init();
		scanf("%ld", &num);
		for(k=0; k<num; k++)
		{
			scanf("%ld %ld %ld %ld", &r1, &c1, &r2, &c2);
			
			for(i=r1; i<=r2; i++)
				for(j=c1-1; j<c2; j++)
				{
					table[i][j] = INFINITY;
				}
		}
		find_submatrix();
	}
	return 0;
}