#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	long long in;
	long long res;
	
    while(scanf("%lld", &in)==1)
	{
		res=1;
		
		while(1)
		{
			res=9*res;
			if(res>=in)
			{
				printf("Stan wins.\n");
				break;
			}
			
			res=2*res;
			if(res>=in)
			{
				printf("Ollie wins.\n");
				break;
			}
		}
	}
	return 0;
}