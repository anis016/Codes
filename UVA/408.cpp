#include<stdio.h>
#include<algorithm>
using namespace std;

long gcd(long a, long b)
{
	if(b>a)
		swap(b, a);
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	long step, mod;
	long output;

	while(scanf("%ld %ld", &step, &mod)==2)
	{
		output = gcd(step, mod);

		if(output==1)
		{
		    printf("%10d%10d    Good Choice\n\n", step, mod);
		}
		else
		{
			printf("%10d%10d    Bad Choice\n\n", step, mod);
		}
	}

	return 0;
}