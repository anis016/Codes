#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 110

long store_r[MAX], store_c[MAX];
long in[MAX][MAX];

int main()
{
	long i, j, k, sumr, sumc, n, l, flag;

	while(scanf("%ld", &n), n)
	{
		flag=0;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				scanf("%ld", &in[i][j]);

		for(i=0, k=0; i<n; i++)
		{
			sumr=0;
			for(j=0; j<n; j++)
				sumr=sumr+in[i][j];
		
			if(sumr%2==1)
			{
				if(k>1)
				{
					flag=1;
					break;
				}
				store_r[k]=(i+1);
				k++;
			}
		}

		if(flag==0)
		{
			for(i=0, l=0; i<n; i++)
			{
				sumc=0;
				for(j=0; j<n; j++)
					sumc=sumc+in[j][i];
			
				if(sumc%2==1)
				{
					if(l>1)
						break;
					store_c[l]=(i+1);
					l++;
				}
			}
		}

		if(k>1 || l>1 || flag==1)
			printf("Corrupt\n");
		else if(k==1 && l==1)
			printf("Change bit (%ld,%ld)\n", store_r[0], store_c[0]);
		else
			printf("OK\n");
	}
	return 0;
}