#include<stdio.h>
#include<iostream>
using namespace std;

long in[100][100];
long str[100][100];

int main()
{
	char con[100], ch;
	long temp[100][100];
	long i, j, k, ii, jj;
	long num, a, b, N, kase, ba, coun, tc;

	coun=1;
	scanf("%ld", &kase);
	while(kase--)
	{
		scanf("%ld", &N);
		
		for(i=1; i<=N; i++)
			scanf("%ld", &str[i]);
		
		for(i=1; i<=N; i++)
			for(k=N; k>=1; k--)
			{
				in[i][k]=str[i][0]%10;
				str[i][0]=str[i][0]/10;
			}
			
			scanf("%ld", &num);
			for(ba=0; ba<num; ba++)
			{
				a=b=0;
				scanf("%s", con);
				ch=cin.get();

				if(ch==' ' && strcmp(con, "row")==0)
				{
					scanf("%ld %ld", &a, &b);

					for(i=1, ii=1; i<=N; ii++, i++)
						for(j=1, jj=1; j<=N; jj++, j++)
							if(i==a)
								temp[ii][jj]=in[b][j];
							else if(i==b)
								temp[ii][jj]=in[a][j];
							else
							    temp[ii][jj]=in[i][j];
				    
				    for(i=1; i<=N; i++) 
						for(j=1; j<=N; j++)
						   in[i][j]=temp[i][j];
				}				

				if(ch==' ' && strcmp(con, "col")==0)
				{
					scanf("%ld %ld", &a, &b);

					for(i=1, ii=1; i<=N; ii++, i++)
						for(j=1, jj=1; j<=N; jj++, j++)
							if(j==a)
								temp[ii][jj]=in[i][b];
							else if(j==b)
								temp[ii][jj]=in[i][a];
							else
								temp[ii][jj]=in[i][j];
					 
					for(i=1; i<=N; i++) 
					   for(j=1; j<=N; j++)
					  	  in[i][j]=temp[i][j];
				}

				if(ch!=' ' && strcmp(con, "inc")==0)
				{
					for(i=1, ii=1; i<=N; ii++, i++)
						for(j=1, jj=1; j<=N; jj++, j++)
						{
							if(++in[i][j]>=10)
								in[i][j]=0;
							
						}
				}

				if(ch!=' ' && strcmp(con, "dec")==0)
				{
				   for(i=1; i<=N; i++)
				        for(j=1; j<=N; j++)
						{
							if(--in[i][j]<0)
								in[i][j]=9;							
    					}
				}

				if(ch!=' ' && strcmp(con, "transpose")==0)
				{
					for(i=1, ii=1; i<=N; ii++, i++)
						for(j=1, jj=1; j<=N; jj++, j++)
						     temp[ii][jj]=in[j][i];

                    for(i=1; i<=N; i++) 
					    for(j=1; j<=N; j++)
						     in[i][j]=temp[i][j];
				}

			}
	
			cout<<"Case #"<<coun++<<endl;
			for(i=1; i<=N; i++)
			{
				for(j=1; j<=N; j++)
				{
					printf("%ld", in[i][j]);
					temp[i][j]=str[i][j]=in[i][j]=0;
				}
				printf("\n");
			}
			printf("\n");

	}
	return 0;
}