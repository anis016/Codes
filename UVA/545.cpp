#include<stdio.h>
#include<math.h>
#define EPSILON pow(10, -9)
#define MAX 9001

int main()
{
    double hold[MAX+100];
	long power[MAX], Case;

	long  n, i;

	hold[0]=5.0;
	power[0]=1;
	
	for(i=1; i<MAX; i++)
	{
		hold[i]=1.0/2.0 * hold[i-1];
		power[i]=power[i-1];

		if((long)hold[i] == 0)
            hold[i] = hold[i]*10.0, power[i]++;
	}

	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld", &n);
		printf("2^-%ld = %.3lfE-%ld\n", n, EPSILON+hold[n-1], power[n-1]);	
	}
	return 0;
}