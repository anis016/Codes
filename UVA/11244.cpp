#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define MAX 150

long i, j;
long row, col;
long r, c, flag, con;
char in[MAX][MAX];

int main()
{
	while(1)
	{
		cin>>row>>col;

		if(row==0 && col==0)
			break;

		for(i=1; i<=row; i++)
			for(j=1; j<=col; j++)
			{
				cin>>in[i][j];
			}
		
		con=0;
		for(i=1; i<=row; i++)
			for(j=1; j<=col; j++)
				if(in[i][j]=='*')
				{
					flag=0;
					r=i;
					c=j;

					if(r==1 && c==1)
					{
						if(in[i][j+1]=='*' || in[i+1][j+1]=='*' || in[i+1][j]=='*')
							flag=1;
					}
					if(r==1 && c!=col)
					{
						if(in[i][j-1]=='*' || in[i+1][j-1]=='*' || in[i+1][j]=='*' || in[i+1][j+1]=='*' || in[i][j+1]=='*')
							flag=1;
					}
					if(r==1 && c==col)
					{
						if(in[i][j-1]=='*' || in[i+1][j-1]=='*' || in[i+1][j]=='*')
							flag=1;
					}
					if(r!=row && c==1)
					{
						if(in[i-1][j]=='*' || in[i-1][j+1]=='*' || in[i][j+1]=='*' || in[i+1][j+1]=='*' || in[i+1][j]=='*')
							flag=1;
					}
					if(r!=row && c!=col)
					{
						if(in[i-1][j-1]=='*' || in[i-1][j]=='*' || in[i-1][j+1]=='*' || in[i+1][j-1]=='*' || in[i+1][j]=='*' || in[i+1][j+1]=='*' || in[i][j-1]=='*' || in[i][j+1]=='*')
							flag=1;
					}
					if(r!=row && c==col)
					{
						if(in[i-1][j]=='*' || in[i-1][j-1]=='*' || in[i+1][j]=='*' || in[i+1][j-1]=='*' || in[i][j-1]=='*')
							flag=1;
					}
					if(r==row && c==1)
					{
						if(in[i-1][j]=='*' || in[i-1][j+1]=='*' || in[i][j+1]=='*')
							flag=1;
					}
					if(r==row && c!=col)
					{
						if(in[i][j-1]=='*' || in[i-1][j-1]=='*' || in[i-1][j]=='*' || in[i-1][j+1]=='*' || in[i][j+1]=='*')
							flag=1;
					}
					if(r==row && c==col)
					{
						if(in[i-1][j]=='*' || in[i-1][j-1]=='*' || in[i][j-1]=='*')
							flag=1;
					}
					if(flag==0)
						con++;
				}				
				cout<<con<<endl;
				
				for(i=0; i<=row; i++)
					for(j=0; j<=col; j++)
						in[i][j]=NULL;
	}
	return 0;
}
