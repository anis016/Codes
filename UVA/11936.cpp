#include<stdio.h>
#include<math.h>

int main()
{
	long test;
	scanf("%ld", &test);
	while(test--)
	{
		long a, b, c;
		scanf("%ld %ld %ld", &a, &b, &c);
		if(a == 0 || b == 0 || c == 0)
		{
			printf("Wrong!!\n");
			continue;
		}

		double s = (a + b + c) / 2.0;

		if( ( (s - double(a) ) <= 0.000000 ) || ( (s - double(b) ) <= 0.000000 ) || ( (s - double(c) ) <= 0.000000 ) ) 
			printf("Wrong!!\n");
		else
			printf("OK\n");
	}
	return 0;
}