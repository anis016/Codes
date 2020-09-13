#include<stdio.h>
#include<math.h>

long step[1000010];

long recurr(long i)
{
	long sum, a, b, c;

	if(step[i])
		return step[i];

	if(i == 0)
		return 1;

	a = recurr( long(i) - sqrt(double(i) ) );
	b = recurr( log(double(i) ) );
	c = recurr( double(i) * sin( double(i) ) * sin( double(i) ) );

	sum = a + b + c;
	return sum;
}

void init()
{
	long i, j;
	for(i=0; i<=1000000; i++)
	{
		j = recurr(i);
		step[i] = j % 1000000;
	}
}

int main()
{	
	long N;

	init();
	while(scanf("%ld", &N)==1)
	{
		if(N < 0)
			break;

		printf("%ld\n", step[N]);
	}

	return 0;
}
