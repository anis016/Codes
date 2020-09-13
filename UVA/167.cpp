#include<stdio.h>

int x[100], hold[100][100], con=1;

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

int in[10][10];

int main()
{
	int i, j, k, kase;
	long sum, final;

	nqueen(1, 8);

	scanf("%d", &kase);
	while(kase--)
	{
		for(i=1; i<=8; i++)
			for(j=1; j<=8; j++)
				scanf("%ld", &in[i][j]);
			
			final=0;
			for(i=1, k=1; i<con; i++)
			{
				k=1;
				sum=0;
				for(j=1; j<=8; j++)
				{
					k=hold[i][j];
					sum+=in[j][k];
				}
				if(final<sum)
					final=sum;
			}
			
			printf("%5ld\n", final);
	}
	return 0;
}
