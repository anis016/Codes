#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	long n, count=0, Case;
	long i, f1, f2, flag;

	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld", &n);
		flag = 0;
		for(i=2; i<n; i++)
		{
			if(n%i==0 && flag==0)
			{
				f1 = i;
				i++;
				flag = 1;
			}
			if(n%i==0 && flag==1)
			{
				f2 = i;				
				break;
			}
		}
		printf("Case #%ld: %ld", ++count, n);
		if((n/f1)>1 && (n/f2)>1)
			printf(" = %ld * %ld = %ld * %ld\n", f1, n/f1, f2, n/f2);
		else if((n/f1)>1 && (n/f2)<1)
			printf(" = %ld * %ld\n", f1, n/f1);
		else if((n/f1)<1 && (n/f2)>1)
			printf(" = %ld * %ld\n", f2, n/f2);
		else
			printf("\n");
	}
	return 0;
}
