#include<stdio.h>
#include<math.h>
#define MAX 200

int main()
{
	long long mat[MAX][MAX];
	long long i, j, num, k, x, d, Case, ii, flag;
	char sp, eq, sp1, sp2;

	scanf("%lld", &Case);
	for(ii=1; ii<=Case; ii++)
	{
		scanf("%c%c%c%c%lld", &eq,&sp1,&sp,&sp2,&num);

		flag=0;
		for(i=0; i<num; i++)
			for(j=0; j<num; j++)
			{
				scanf("%lld", &mat[i][j]);

				if(mat[i][j]<0)
					flag=1;
			}

		if(flag==1)
		{
			printf("Test #%lld: Non-symmetric.\n", ii);
			continue;
		}

		j=0;
		k=num-1;
		if( (num%2)==0)
			d=num;
		else
			d=(num/2)+1;
		for(i=0, x=num-1; i<d; x--, i++)
		{
			for(j=0, k=num-1; j<num; j++, k--)
				if(mat[i][j]!=mat[x][k])
				{
					flag=1;
					break;
				}
			if(flag==1)
				break;
		}

		if(flag==1)
		{
			printf("Test #%lld: Non-symmetric.\n", ii);
			continue;
		}
		else
			printf("Test #%lld: Symmetric.\n", ii);

	}


	return 0;
}