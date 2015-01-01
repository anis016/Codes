#include<stdio.h>

long abs(long a)
{
	if(a < 0)
		return -1*a;
	return a;
}

int main()
{
	long a, b, Case;
	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld %ld", &a, &b);
		if(b==0)
		{
			printf("1\n");
			continue;
		}

		else if( abs(a)==abs(b)  )
		{
			printf("4\n");
			continue;
		}
		else if(a==0)
		{
			printf("2\n");
			continue;
		}
		else
			printf("TOO COMPLICATED\n");
			 
	}
	return 0;
}