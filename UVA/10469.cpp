//  & AND
//  | inclusive OR (OR)
//  ^ exclusive OR (XOR)

#include<stdio.h>

int main()
{
	long long in1, in2, hold;

	while(scanf("%lld %lld", &in1, &in2)!=EOF)
	{
	   hold=in1^in2;
	   printf("%lld\n", hold);
	}
	return 0;
}