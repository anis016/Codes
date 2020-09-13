#include<stdio.h>

int main()
{
	double ncar, ncow, nshow;
	double ans;

	while(scanf("%lf %lf %lf", &ncow, &ncar, &nshow)!=EOF)
	{
		ans=  (ncar * (ncow + ncar - 1))/((ncow+ncar) * (ncow + ncar - nshow - 1));
 	    printf("%.5lf\n", ans);
	}
	return 0;
}
