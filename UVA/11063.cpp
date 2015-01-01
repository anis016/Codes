#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 10001

long number[MAX];
long temp[MAX];
long length;
long N;

bool Bsearch(long sum)
{
	long high = length - 1;
	long low = 0;
	long mid;

	while(low <= high)
	{
		mid = (long) (low + high) / 2;
		
		if(temp[mid] < sum)
			low = mid + 1;
		else if(temp[mid] > sum)
			high = mid - 1;
		else if(sum == temp[mid])
			return true;
	}
	return false;
}

void init()
{
	if(N > length)
		N = length;
	else
		N = N;

	for(long i = 0; i <= N; i++)
		temp[i] = number[i] = 0;
	return ;
}

int main()
{
	long i, j, cnt = 1;

	while(scanf("%ld", &N)==1)
	{
		bool s = false;

		scanf("%ld", &number[0]);
		if(number[0] <= 0)
			s = true;

		for(i = 1; i < N; i++)
		{
			scanf("%ld", &number[i]);
			if( (number[i - 1] >= number[i]) )
			{
				s = true;
			}
		}

		if(s == true)
		{
			printf("Case #%ld: It is not a B2-Sequence.\n", cnt++);
			printf("\n");
			continue;
		}

		long sum = 0;

		length = 0;
		bool f = false;
		for(i = 0; i < N; i++)
		{
			for(j = i; j < N; j++)
			{
				sum = number[i] + number[j];
				
				bool flag = Bsearch(sum);
				if(flag == true)
				{
					f = true;
					break;
				}
				temp[length] = sum;
				length++;

				sort(temp, temp + length);
			}
			if(f ==true	)
				break;
		}

		if(f == true)
			printf("Case #%ld: It is not a B2-Sequence.\n", cnt++);
		else
			printf("Case #%ld: It is a B2-Sequence.\n", cnt++);

		printf("\n");
		init();
	}
	return 0;
}