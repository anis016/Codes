#include<stdio.h>

typedef long tall;

int main()
{
	tall test;
	tall i, count=0;
	tall x1, y1, x2, y2, ans1, ans2, hold1, hold2;
	tall t, p;

	scanf("%lld", &test);
	count=1;
	for(i=0; i<test; i++)
	{
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		  hold1=(x1+y1);                  /////////to get the index
		  hold2=(x2+y2);				  /////////to get the index

		ans1=(hold1*(hold1+1))/2;          ////////it forms a natural number series
		t=ans1+x1;						   ////////the line should be measured with respect to x-axis
		
		ans2=(hold2*(hold2+1))/2;          ////////it forms a natural number series
		p=ans2+x2;

		if(t>p)
		    printf("Case %lld: %lld\n",count++, t-p);
		else
			printf("Case %lld: %lld\n",count++, p-t);

	}

	return 0;
}