#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define MAX 205
#define max 200
typedef long tall;

char in[MAX][MAX];

tall i, j;
tall row, col, con;
tall r, c, flag;

int main()
{
	tall count[max][max];
	con=1;

	while(scanf("%lld %lld", &row, &col), row, col)
	{
		for(i=0; i<row; i++)
			for(j=0; j<col; j++)
			{
				in[i][j]=NULL;
				cin>>in[i][j];
				count[i][j]=0;
			}
			
		for(i=0; i<row; i++)
			for(j=0; j<col; j++)
				if(in[i][j]=='*')
				{
					r=i;
					c=j;
					
					if(r==0 && c==0)
					{
						count[i][j+1]++;
						count[i+1][j+1]++;
						count[i+1][j]++;
					}
					else if(r==0 && c!=col)
					{
						count[i][j-1]++;
						count[i+1][j-1]++;
						count[i+1][j]++;						
						count[i+1][j+1]++;
						count[i][j+1]++;
					}
					else if(r==0 && c==col)
					{
						count[i][j-1]++;
					    count[i+1][j-1]++;
						count[i+1][j]++;
					}
					else if(r!=row && c==0)
					{
						count[i-1][j]++;
						count[i-1][j+1]++;
						count[i][j+1]++;
						count[i+1][j+1]++;
						count[i+1][j]++;
					}
					else if(r!=row && c!=col)
					{
						count[i-1][j-1]++;
						count[i-1][j]++;
						count[i-1][j+1]++;
						count[i+1][j-1]++;
						count[i+1][j]++;
						count[i+1][j+1]++;
						count[i][j-1]++;
						count[i][j+1]++;
					}
					else if(r!=row && c==col)
					{
						count[i-1][j]++;
						count[i-1][j-1]++;
						count[i+1][j]++;
					    count[i+1][j-1]++;
						count[i][j-1]++;
					}
					else if(r==row && c==0)
					{
						count[i-1][j]++;
						count[i-1][j+1]++;
					    count[i][j+1]++;
					}
					else if(r==row && c!=col)
					{
						count[i][j-1]++;
						count[i-1][j-1]++;
						count[i-1][j]++;
						count[i-1][j+1]++;
						count[i][j+1]++;
					}
					else if(r==row && c==col)
					{
						count[i-1][j]++;
						count[i-1][j-1]++;
						count[i][j-1]++;
					}
				}

				if(flag==1)
					printf("\n");
				
				printf("Field #%lld:\n", con++);
				
				for(i=0; i<row; i++)
				{
					for(j=0; j<col; j++)
						if(in[i][j]=='*')
							printf("*");
						else
							cout<<count[i][j];				
						printf("\n");
				}
				flag=1;
	}
	return 0;
}
