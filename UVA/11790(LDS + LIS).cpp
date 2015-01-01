#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 10000
#define max(x, y) x > y ? x : y
long mat[MAX], matr[MAX], N, weigh[MAX], weighr[MAX], pred[MAX];

void read_input()
{
	long i;

	scanf("%ld", &N);

	int j = N - 1;
	for(i=0; i<N; i++)
	{
		scanf("%ld", &mat[i]);
		matr[j--] = mat[i];
	}

	j = N - 1;
	for(i=0; i<N; i++)
	{
		scanf("%ld", &weigh[i]);
		weighr[j--] = weigh[i];
	}

	return ;
}

int LIS()
{
	int i, j;

	for(i = 0; i < N; i++)
	{
		pred[i] = weigh[i];
		for(j = 0; j < i; j++)
			if( mat[i] < mat[j] )
				pred[i] = max(pred[i], pred[j] + weigh[i]);
	}
	return *max_element(pred,pred+N);
}

int LDS()
{
	int i, j;

	for(i = 0; i < N; i++)
	{
		pred[i] = weighr[i];
		for(j = 0; j < i; j++)
			if( matr[i] < matr[j] )
				pred[i] = max(pred[i], pred[j] + weighr[i]);
	}
	return *max_element(pred,pred+N);
}

int main()
{
	int cnt = 1;
	int Case;

	scanf("%d", &Case);
	while(Case--)
	{
		read_input();
		
		int lenI = LIS();
		int lenD = LDS();
		
		swap(lenI, lenD);
		if(lenI >= lenD)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", cnt++, lenI, lenD);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", cnt++, lenD, lenI);
	}
	return 0;
}