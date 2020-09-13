
#include<stdio.h>
#include<math.h>

    /******** need to find the value for 3 terms so n=3 *****/
int main()
{
	long double in, m, ans;
	double const n=3, p=pow(3, 2);  

	while(scanf("%Lf", &in)!=EOF)
	{
	/******* m= mth term for the number that is given *******/

		m=(in+1)*(((in-1)/2)+1);          
		 
	/******* n=how many terms from last, p=square of n ********/ 
		
		ans=n*m-p;
		printf("%.0Lf\n",ans);
	}
	return 0;
}