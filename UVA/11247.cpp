#include<stdio.h>

typedef long LL;

int main()
{
	LL m, vmod, vdiv, x;
	
	while(scanf("%lld %lld", &m, &x)==2)
	{
		if(m==0 && x==0.00)
			break;

		if(x==100)
		{
			printf("Not found\n");
			continue;
		}

		vdiv = ( (m - 1) * 100 ) / (100 - x) ;
		if(vdiv < m)
		{
			printf("Not found\n");
			continue;
		}
		vmod = ( (m - 1) * 100 ) % (100 - x) ;

		if(vmod==0)
			printf("%lld\n", vdiv-1);
		else
			printf("%lld\n", vdiv);
	}
	return 0;
}