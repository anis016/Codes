#include<stdio.h>

int x[100], hold[100][100], con;

int place(int k, int i)
{
	int j;
	for(j=1;j<k;j++)
	{
		if((x[j]==i)||((x[j]-i)==(j-k))||(-(x[j]-i)==(j-k))||((x[j]-i)==-(j-k)))
			return 0;
	}
	return 1;
}

void nqueen(int k,int n)
{
	int i,j;
	for(i=1;i<=n;i++)
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				for(j=1;j<=n;j++)
					hold[con][j]=x[j];
				con++;
			}
			else
				nqueen(k+1,n);
		}
}

int main()
{
	int i, k, kase;
	int row, col, count, flag=0;

	nqueen(1, 8);
	scanf("%d", &kase);
	while(kase--)
	{
		count=0;
		scanf("%d %d",&row, &col);

		if(flag==1)
			printf("\n");
		flag=1;

		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		
		for(i=0; i<con; i++)
		{
			if(hold[i][col]==row)
			{
				printf("%2d     ",++count);
				for(k=1; k<=8; k++)
					printf(" %d", hold[i][k]);
				printf("\n");
			}
		}
	}
	return 0;
}
