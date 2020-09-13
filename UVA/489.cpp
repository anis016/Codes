#include<stdio.h>
#include<string.h>
#define MAX 21000

long temp[MAX];
char guess[MAX], store[MAX], puzzle[MAX];

int search(char ch, int len)
{
	for(int i = 0; i < len; i++)
	{
		if(ch == store[i])
			return 1;
	}
	return 0;
}

int check_puzzle(int lenp)
{
	for(int i = 0; i < lenp; i++)
		if(puzzle[i] != '.')
			return 0;
	return 1;
}

void init(int len)
{
	for(int i = 0;  i < len; i++)
		store[i] = 0;
}

int main()
{
	int i, j, leng, lenp, round, count, flag, test, c;

	test=1;
	while(scanf("%d", &round) && round >= 0)
	{		
		count=flag=0;

		scanf("%s", puzzle);
		scanf("%s", guess);

		lenp=strlen(puzzle);
		leng=strlen(guess);

		printf("Round %ld\n", round);
		count = 0;

		int k = 0;
		for(i=0; i<leng; i++)
		{
			flag = c = 0;

			char ch = guess[i];

			for(j=0; j<lenp; j++)
			{
				if(ch == puzzle[j] )
				{
					puzzle[j] = '.';
					flag = 1;
				}
			}

			if(flag == 0)
			{
				int f = search(ch, k);
				if(f == 0)
				{
					count ++;
					store[k++] = ch;
				}

				if(count >= 7)
					break;
			}

			c = check_puzzle(lenp);
			if(c == 1)
				break;
		}
		store[k] = '\0';

		if(c == 1)
		{
			int lens = strlen(store);
			if( lens <= leng)
			{
				printf("You win.\n");
				init(k);
			}
		}

		else if(c == 0 && count >= 7)
			printf("You lose.\n");
		else
			printf("You chickened out.\n");

		init(k);

	}
	return 0;
}