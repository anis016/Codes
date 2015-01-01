#include<stdio.h>

int main()
{
	long x_in[100000], y_in[100000], div_x, div_y, test, i, j;

	while(scanf("%ld", &test), test)
	{
		scanf("%ld %ld", &div_x, &div_y);
		if(test<0)
			break;
		else
		{
			for(i=0; i<test; i++)
				scanf("%ld %ld", &x_in[i], &y_in[i]);
			
			for(j=0; j<test; j++)
			{
				if(x_in[j]==div_x || y_in[j]==div_y)
					printf("divisa\n");
				else if(x_in[j]>div_x && y_in[j]>div_y)
					printf("NE\n");
				else if(x_in[j]<div_x && y_in[j]>div_y)
					printf("NO\n");
				else if(x_in[j]<div_x && y_in[j]<div_y)
					printf("SO\n");
				else if(x_in[j]>div_x && y_in[j]<div_y)
					printf("SE\n");
			}
		}
	
	}
	return 0;
}
