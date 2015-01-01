#include<stdio.h>
#define MAX 110

long area[MAX][MAX];

void init()
{
	long i, j;
	for(i=0; i<=MAX; i++)
		for(j=0; j<=MAX; j++)
			area[i][j]=0;
}

int main()
{
	long test;
	long i, j;
	long a_left, a_down, a_right, a_up, b_left, b_down, b_right, b_up;
	long A1, A2, A3;
	long count;

	count=1;
	scanf("%ld", &test);
	while(test--)
	{
		scanf("%ld %ld %ld %ld", &a_left, &a_down, &a_right, &a_up);
		scanf("%ld %ld %ld %ld", &b_left, &b_down, &b_right, &b_up);

		for(i=a_left; i<a_right; i++)
			for(j=a_down; j<a_up; j++)
			{
				area[i][j]++;
			}
		
		for(i=b_left; i<b_right; i++)
		{
			for(j=b_down; j<b_up; j++)
			{
				area[i][j]++;
			}
		}

		A1=A2=A3=0;
		for(i=0; i<=100; i++)
			for(j=0; j<=100; j++)
			{
				if(area[i][j]==1)
					A1++;
				else if(area[i][j]==2)
					A2++;
			}
		A3=10000-(A1+A2);

		printf("Night %ld: %ld %ld %ld\n",count++, A2, A1, A3);

		init();
	}

	return 0;
}
