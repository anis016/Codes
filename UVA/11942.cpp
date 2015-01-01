#include<algorithm>
#include<stdio.h>
using namespace std;

int order[20], tempi[20], tempd[20];

int main()
{
	int test;

	scanf("%d", &test);
	printf("Lumberjacks:\n");
	while(test--)
	{
		int cnt = 0;
		while(cnt < 10)
		{
			int x;

			scanf("%d", &x);
			order[cnt] = x;
			tempi[cnt] = x;
			
			cnt++;
		}

		sort(tempi, tempi + 10);
		for(int j = cnt - 1, i = 0 ; i < 10; i++)
		{
			tempd[i] = tempi[j];
			j--;
		}

		int flagi = 0, flagd = 0;
		for(int i = 0; i < 10; i++)
		{
			if( !(tempi[i] == order[i]) )
			{
				flagi = 1;
				break;
			}
		}

		for(int i = 0; i < 10; i++)
		{
			if( !(tempd[i] == order[i]) )
			{
				flagd = 1;
				break;
			}
		}

		if(flagi == 0 || flagd == 0)
			printf("Ordered\n");
		else
			printf("Unordered\n");
	}
	return 0;
}