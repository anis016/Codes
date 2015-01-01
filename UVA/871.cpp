#include<stdio.h>
#include<string.h>
#define MAX 50

long table[MAX][MAX], max, N, maxr, maxc;

void readcase(void )
{
   long j, k;
   char input[100];
   
   N = 0;
   while(gets(input)) 
   {
	   if(strlen(input)<1) 
		   break;

	   for(j=0; input[j]; j++)
	   {
		   k = input[j] - '0';
		   if(k == 1)
			   table[N][j] = 1;
		   else table[N][j] = 0;		 
	   }
	   N++;
	   maxc=strlen(input);
   }
 
   maxr=N;

   return ;
}

void dfs(long row, long col)
{
	long i, j;

	table[row][col]=0;

	for(i=-1; i<=1; i++)
		for(j=-1; j<=1; j++)
		{
			if( ( (row+i <0 ) || (col+j < 0) ) || ( (row+i >=maxr) || (col+j >= maxc) ) )
				continue;
			
			if(table[row+i][col+j]==1)
			{
				max++;
				dfs(row+i, col+j);
			}
		}
}

int main()
{
//	freopen("871.txt", "r", stdin);
	long i, j, max1, res, Case;
	char input[1000];

	gets(input);
	sscanf(input,"%ld",&Case);
	gets(input);

	while(Case--)
	{
		readcase();
		res=0;
		for(i=0; i<maxr; i++)
			for(j=0; j<maxc; j++)
			{
				max=0;
				if(table[i][j]==1)
				{
					max=1;
					dfs(i, j);
				}
				max1=max;
				max=0;

				if(max1>res)
					res=max1;
			}
			if(res>=1)
				printf("%ld\n", res);
			else
				printf("%ld\n", 0);
			if(Case)
				printf("\n");
	}
	return 0;
}