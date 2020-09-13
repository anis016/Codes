#include<stdio.h>
#define MAX 11

char str[MAX][MAX];
int N;

void read_input()
{
	int i;
	for(i = 0; i < N; i++)
		scanf("%s", str[i]);
}

bool check_up(char ch, int x, int y)
{
	if(str[x - 1][y] == ch)
		return false;
	return true;
}

bool check_down(char ch, int x, int y)
{
	if(str[x + 1][y] == ch)
		return false;
	return true;
}

bool check_left(char ch, int x, int y)
{
	if(str[x][y - 1] == ch)
		return false;
	return true;
}

bool check_right(char ch, int x, int y)
{
	if(str[x][y + 1] == ch)
		return false;
	return true;
}

void process()
{
	int i, j, cnt;
	char ch;
	bool flagu = false, flagd = false, flagl = false, flagr = false, flag = false;
	for(i = 0; i < N; i++)
	{
		ch = 'A';
		cnt = 0;
		for(j = 0; j < N; )
		{
			if(str[i][j] != '.')
			{
				j++;
				ch = 'A';
				cnt = 0;
				continue;
			}

			flagu = check_up(ch, i, j);
			flagd = check_down(ch, i, j);
			flagl = check_left(ch, i, j);
			flagr = check_right(ch, i, j);

			if(flagu == true && flagd == true && flagl == true && flagr == true)
			{
				str[i][j] = ch;			
				j++;
				cnt = 0;
			}
			else
			{
				ch = 'A' + cnt;
				cnt++;
			}
		}
		puts(str[i]);
	}

	return ;
}

int main()
{
	int Case, k = 0;

	scanf("%d", &Case);
	while(Case--)
	{
		scanf("%d", &N);

		read_input();

		printf("Case %d:\n", ++k);
		process();
	}
	return 0;
}