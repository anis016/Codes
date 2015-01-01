#include<stdio.h>
#include<string.h>
#define MAX 150

char in[MAX][MAX];
char tempo[MAX][MAX];

long maxr, maxc, count=0;

void init(void)
{
	long i, j;
	for(i=0; i<=maxr; i++)
	{
		for(j=0; j<=maxc; j++)
		{
			in[i][j]=tempo[i][j];
		}
	}

	return ;
}


void dfs(long row, long col)
{
	long i, j;

	in[row][col]='L';

	for(i=-1; i<=1; i++)
		for(j=-1; j<=1; j++)
		{
			if( ( (row+i <0 ) || (col+j < 0) ) || ( (row+i >=maxr) || (col+j >= maxc) ) )
				continue;
			
			if(in[row+i][col+j]=='W')
			{
				count++;
				dfs(row+i, col+j);
			}
		}
}

int main()
{
	long i;
	long r, c;
	char temp[MAX], xx[MAX];
	long len;
	long Case;

	gets(xx);
	sscanf(xx, "%ld", &Case);
	gets(xx);

	while(Case--)
	{		
		init();

		i=0;
		while(1)
		{
			gets(in[i]);
			
			if(in[i][0]!='L' && in[i][0]!='W' )
			{
				strcpy(temp, in[i]);
				break;
			}		
			strcpy(tempo[i], in[i]);
			i++;
		}
		maxr=i;
		
		sscanf(temp, "%ld %ld", &r, &c);

		len=strlen(in[0]);
		maxc=len;
		
		if(in[r-1][c-1]=='L' || ( r>maxr || c>maxc) )
			printf("0\n");
		else
		{
			count=0;
			dfs(r-1, c-1);
			printf("%ld\n", count+1);
			count=0;

		}
		init();

		while(gets(temp) && temp[0])
		{
			sscanf(temp,"%d %d",&r,&c);

			if(in[r-1][c-1]=='L' || ( r>maxr || c>maxc) )
				printf("0\n");
			else
			{
				count=0;
				dfs(r-1,c-1);
			    printf("%ld\n", count+1);
			}
			init();
		}

		if(Case>0)
		   printf("\n");
	}

	return 0;
}
