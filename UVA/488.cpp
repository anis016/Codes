#include<stdio.h>

int main()
{
	long a,f,space,t,i,j,k,kk;
	scanf("%ld",&t);
	space=0;
	for(kk=1;kk<=t;kk++)
	{
		scanf("%ld%ld",&a,&f);
		
		for(i=0;i<f;i++)
		{
			if(space==1)
				printf("\n");
			space=1;

			for(j=1;j<=a;j++)
			{
				for(k=1;k<=j;k++)
					printf("%ld",j);
				printf("\n");
			}

			for(j=a-1;j>0;j--)
			{
				for(k=1;k<=j;k++)
					printf("%ld",j);
				printf("\n");
			}
		}
	}
	return 0;
}
	
