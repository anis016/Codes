#include<stdio.h>
#include<string.h>
#define max 2000

char in[20000];

long hold[max][max], temp[max][max];
long R[2][2]=   {   {1, 0},
					{1, 1}
				};
long L[2][2]=   {   {1, 1},
					{0, 1}
				};

long len, i, j, k, con, flag;

int main()
{
	long kase;
	char xx[20000];

	gets(xx);
	sscanf(xx, "%ld", &kase);

	while(kase--)
	{
		gets(in);		
		len=strlen(in);

		flag=0;
		for(con=0; con<len; con++)
		{
			if(flag==0)
			{
				if(in[con]=='L')
				{
					for(i=0; i<2; i++)
						for(j=0; j<2; j++)
							temp[i][j]=L[i][j];

				}			
				else if(in[con]=='R')
				{
					for(i=0; i<2; i++)
						for(j=0; j<2; j++)
							temp[i][j]=R[i][j];
				}
			}
			
			if(flag==1)
			{
				if(in[con]=='L')
				{
					for(i=0; i<2; i++)                 
					{
						for(j=0; j<2; j++)
						{
							for(k=0; k<2; k++)
								hold[i][j]+=temp[i][k]*L[k][j];
						}
					}
					for(i=0; i<2; i++)          //// copy
					{
						for(j=0; j<2; j++)
						{
							temp[i][j]=hold[i][j];
							hold[i][j]=0;
						}
					}
				}
				
				else if(in[con]=='R')
				{
					for(i=0; i<2; i++)                 
					{
						for(j=0; j<2; j++)
						{
							for(k=0; k<2; k++)
								hold[i][j]+=temp[i][k]*R[k][j];
						}
					}
					for(i=0; i<2; i++)          //// copy
					{
						for(j=0; j<2; j++)
						{
							temp[i][j]=hold[i][j];
							hold[i][j]=0;
						}
					}			
				}
			}
			flag=1;
		}
		
		printf("%ld/",  temp[1][0]+temp[1][1]);
		printf("%ld\n", temp[0][0]+temp[0][1]);
	}
	return 0;
}