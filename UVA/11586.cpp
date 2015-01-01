#include<stdio.h>

int main()
{
	long Case;

	scanf("%ld", &Case);
	getchar();
	while(Case--)
	{
		char ch;

		int M = 0;
		int F = 0;
		while(1)
		{
			ch = getchar();

			if(ch == '\n')
				break;

			else if(ch == 'M')
				M++;
			else if(ch == 'F')
				F++;
		}
		if(M > 1 && M == F)
			printf("LOOP\n");
		else
			printf("NO LOOP\n");

	}
	return 0;
}