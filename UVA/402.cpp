#include<cstdio>
#include<iostream>
using namespace std;

#define MAX 1000

int people[MAX];
int deck[MAX];
int card, total;

void read_input()
{
	int i;

	for(i = 0; i < 20; i++)
		scanf("%ld", &deck[i]);

	for(i = 0; i < total; i++)
		people[i] = i + 1;

	return ;
}

int remain()
{
	int count = 0;
	int i, j;
	int temp[MAX];

	for(i = 0, j = 0; i < total; i++)
	{
		if(people[i] == 0)
			continue;
		else
			temp[j++] = people[i];

	}

	count = 0;
	for(i = 0; i < j; i++)
		people[i] = temp[i];

	for(i = j; i < total; i++)
		people[i] = 0;

	total = j;

	return j;
}

void cut(int c)
{
	int j = 0, k = 9999999;

	while(j < k)
	{
		j += c - 1;

		if(k <= card)
			break;

		people[j] = 0;
		k = remain();
	}
}

void init()
{
	for(int i = 0; i <= 50; i++)
		deck[i] = people[i] = 0;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	
	int i, j, cnt = 0;
	bool flag;

	while(scanf("%d", &total)==1)
	{
		scanf("%d", &card);

		flag = false;
		read_input();

		if(total <= card) 
			flag=true;

		if(flag == false)
		{
			j = 99999;
			for(i = 0; i < 20; i++)
			{
				if(j == card)
					break;

				cut(deck[i]);
				j = remain();
			}
		}
		
		printf("Selection #%ld\n", ++cnt);
		printf("%d", people[0]);
		for(i = 1; i <= 50; i++)
		{
			if(people[i] == 0)
				break;

			printf(" %d", people[i]);
		}
		printf("\n\n");

		init();
	}
	return 0;
}
