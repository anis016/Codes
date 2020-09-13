#include<stdio.h>
#include<string.h>
#define MAX 3050

long in[MAX], hold[MAX];

int main()
{
	long n, i, flag=0, diff, j, k,count, m,f;

	while(scanf("%ld", &n)==1)
	{
		f=0;
		memset(hold, '0', sizeof(hold));
		memset(in, '0', sizeof(in));
		
		flag=0;	
		for(i=0; i<n; i++)
		{
			scanf("%ld", &in[i]);
		}

		diff=count=0;
		for(i=1,j=0; i<n; i++)
		{
			diff=in[i-1]-in[i];
			
			if(diff<0)
				diff=-1*diff;

			if(diff<1 || diff>(n-1) )
			{
				flag=1;
				break;
			}

			hold[j]=diff;
			j++;

			if(f==0)
				f=1;
			else if(f==1)
			{
			for(k=0; k<j-1; ++k)
			{
				if(hold[k]==diff)
				{
						flag=1;
						break;
				}
			}
			}

			if(flag==1)
				break;
		}

		if(flag==1)
			printf("Not jolly\n");
		else
			printf("Jolly\n");
	}
	return 0;
}
