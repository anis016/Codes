#include<stdio.h>

long a[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int main()
{
	long k;

	while(scanf("%ld",&k)==1,k!=0)
	{
		printf("%ld\n",a[k]);
	}

	return 0;
}