#include<stdio.h>

long i, array[4], n;

int main()
{
	long temp,  x, y;
	scanf("%ld",  &n);

	for(i=1; i<=n; i++)
	{
		scanf("%ld %ld %ld",  &array[0],  &array[1],  &array[2]);

		if(array[0]==array[1] || array[0]==array[2] || array[2]==array[1])
			printf("Case %ld: 0\n", i);
		else
		{
			for(x=0; x<3; x++)
			{
				for(y=0; y<2; y++)
				{
					if(array[y]>array[y+1])
					{
						temp = array[y+1];
						array[y+1] = array[y];
						array[y] = temp;
					}			
				}
			}
		    printf("Case %ld: %ld\n", i, array[1]);
		}

	}
	return 0;
}