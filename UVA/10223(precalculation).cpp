#include<stdio.h>

int main()
{
	long tree,i;
	long node[]={1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700,1767263190 };
	
	while(scanf("%ld",&tree)==1)
	{
		for(i=0;i<19;i++)
			if(node[i]==tree)
			{
				printf("%ld\n",i+1);
				break;
			}
	}
	return 0;
}

/*Cn=(2n)!/((n+1)!n!) n>=0 */