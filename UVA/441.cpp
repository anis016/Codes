#include<stdio.h>

long mat[100], N;

void print()
{
	long i, j, k, l, m, n;

	for(i=0; i<N-5; i++)
		for(j=i+1; j<N-4; j++)
			for(k=j+1; k<N-3; k++)
				for(l=k+1; l<N-2; l++)
					for(m=l+1; m<N-1; m++)
						for(n=m+1; n<N; n++)
							printf("%ld %ld %ld %ld %ld %ld\n", mat[i], mat[j], mat[k], mat[l], mat[m], mat[n]);
}

int main()
{
	long i, t;
	
	t = 0;
	while(scanf("%d", &N) == 1 && N > 0)
	{
		if (t != 0)
			printf("\n");

		for(i=0; i<N; i++)
			scanf("%ld", &mat[i]);
		print();
		t++;
	}
	return 0;
}