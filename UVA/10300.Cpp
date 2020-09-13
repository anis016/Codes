#include<stdio.h>

int main()
{
	long test, test1, i, t;
	long s_farm, n_ani, e_fre, hold;

	while(scanf("%ld", &test)!=EOF)
	{
		for(t=0; t<test; t++)
		{
		   scanf("%ld", &test1);
		   
		   hold=0;
		   for(i=1; i<=test1; i++)
		   {
			  scanf("%ld %ld %ld", &s_farm, &n_ani, &e_fre);
			  hold+=(s_farm*e_fre);
		   }

		   printf("%ld\n", hold);
	       
		}
	}

	return 0;
}