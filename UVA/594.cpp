/*
1111111100000000 => 0XFF00
11111111         => 0XFF
*/

#include<stdio.h>

int main()
{
	long n;
	long a, b, c, d;

	while(scanf("%ld", &n) == 1)
	{
		a = (n >> 24L) & 0xFF;
		b = (n >> 8L) & 0xFF00;
		c = (n & 0xFF00) << 8L;
		d = (n & 0xFF) << 24L;

		printf("%d converts to %d\n", n, a | b | c | d );
	}
	return 0;
}