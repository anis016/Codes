#include<stdio.h>
#define MAX 1000
#define INF -10001

long A[MAX][MAX], table[MAX][MAX];
long N;

void init(void )
{
	long i, j;

	for(i=0; i<=N; i++)
		for(j=0; j<=N; j++)
			table[i][j]=0;

	return ;
}

long find_submatrix(void )
{
	long max, count, ijk, ij, k, diff, i, j;

	for(i=1; i<=N; i++)
		for(j=0; j<N; j++)
			table[i][j] = table[i][j] + table[i-1][j];       /* Adding row-wise one before the other */

	max = table[1][0];                  /// default max be table[1][0]
	/*  Algo Part O(n^3)*/

	for(k=1; k<=N; k++)                /* checking from row order k -> i partiton along with coloumn */
		for(i=0; i<=(N-k); i++)        // each time the submatrix reduces for checking coz k value(checking) increase.
		{							   // checking starts from i = 0 && j = 0 (matrix input has taken from i = 1)
			count=0;				   // making table[0][j] = 0
			for(j=0; j<N; j++)
			{
				if(count>=0)
				{
					ijk = table[i+k][j];    //// traverse from left -> right and do row-wise subtracting (i+k) - (i) (immediate)
					ij = table[i][j];		//// for each loop count increases if "subsequent" rectangular '0' is found
  
					diff = ijk - ij;

					count+= diff;
				}
				else
				{
					ijk = table[i+k][j];
					ij = table[i][j];

					diff = ijk - ij;

					count = diff;
				}

				if(count>max)
					max=count;         //// max only increses if later one is greater then previous one, this checks how much greater thus finding how many '0' exists in rectangle
			}
		}

	return max;
}



int main()
{
//	freopen("836.in", "r", stdin);

	long i, j, res;
	
	while(scanf("%ld", &N)==1)
	{
		for(i=1; i<=N; i++)
			for(j=0; j<N; j++)
				scanf("%ld", &table[i][j]);          /// take the input values and check if there is 1 make it INF else put 1 (for this problem only)
			
			res=find_submatrix();
			if(res<0)
				printf("0\n");
			else
				printf("%ld\n", res);
			init();
	}
	return 0;
}