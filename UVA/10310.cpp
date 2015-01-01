#include<stdio.h>
#include<math.h>
#define MAX 2000

#define EPSILON pow(10,-9)

long double find_distance(long double a, long double b, long double ra1, long double ra2)
{
	return (sqrt( ( (a-ra1)*(a-ra1)  + (b-ra2)*(b-ra2) ) ) );
}

long double d1, d2, g1, g2, dis1, dis2, ho1[MAX], ho2[MAX], dog, gop;
long n, i, flag;

int main()
{
	while(scanf("%ld", &n)!=EOF)
	{
		scanf("%Lf %Lf", &g1, &g2);
		scanf("%Lf %Lf", &d1, &d2);
		
		for(i=0; i<n; i++)
			scanf("%Lf %Lf", &ho1[i], &ho2[i]);

		flag=0;		
		dis1=dis2=0.0;
		for(i=0; i<n; i++)
		{
			dis1=find_distance(g1+EPSILON, g2+EPSILON, ho1[i]+EPSILON, ho2[i]+EPSILON);     /// gopher	
			dis2=find_distance(d1+EPSILON, d2+EPSILON, ho1[i]+EPSILON, ho2[i]+EPSILON);     /// dog
				
			gop=dis1;
			dog=dis2/2.0;
						
			if(gop <= dog)
			{
				printf("The gopher can escape through the hole at (%.3Lf,%.3Lf).\n", ho1[i]+EPSILON, ho2[i]+EPSILON);
				flag=1;
				break;
			}
		}
		
		if(flag==0)
			printf("The gopher cannot escape.\n");
	}
	return 0;
}