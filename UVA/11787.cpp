#include<stdio.h>
#include<string.h>
#define MAX 1000
char str[MAX];

int read_character(char ch)
{
	if(ch == 'B')
		return 1;
	else if(ch == 'U')
		return 10;
	else if(ch == 'S')
		return 100;
	else if(ch == 'P')
		return 1000;
	else if(ch == 'F')
		return 10000;
	else if(ch == 'T')
		return 100000;
	else if(ch == 'M')
		return 1000000;
}

int insert_ch(char ch)
{
	if(ch == 'B')
		return 1;
	else if(ch == 'U')
		return 2;
	else if(ch == 'S')
		return 3;
	else if(ch == 'P')
		return 4;
	else if(ch == 'F')
		return 5;
	else if(ch == 'T')
		return 6;
	else if(ch == 'M')
		return 7;
}

long store[200];
int tempo[MAX], J;

bool check_error(char ch)
{
	if(store['B'] > 9 || store['U'] > 9 || store['S'] > 9 || store['P'] > 9 || store['F'] > 9 || store['T'] > 9 || store['M'] > 9)
		return true;
	else
	{
		tempo[J] = insert_ch(ch);
		J++;

		if(J >= 2)
		{
			int i;
			bool flag_f = false, flag_r = false;
			for(i = 1; i < J; i++)
				if(tempo[i] >= tempo[i - 1])
					continue;
				else
				{
					 flag_f = true;
					 break;
				}

			for(i = J - 1; i > 0; i--)
				if(tempo[i] <= tempo[i - 1])
					continue;
				else
				{
					 flag_r = true;
					 break;
				}

			if(flag_f == true && flag_r == true)
				return true;
		}
	}
	return false;
}

void init()
{
	store['B'] = store['U'] = store['S'] = store['P'] = store['F'] = store['T'] = store['M'] = 0;
	J = 0;
}

int main()
{
	char xx[MAX];
	int Case;

	gets(xx);
	sscanf(xx, "%d", &Case);

	while(Case--)
	{
		J = 0;
		gets(str);
		int len = strlen(str);

		int i, j;
		bool flag = false;
		for(i = 0, j = 0; i < len; i++)
		{
			store[str[i]]++;

			flag = check_error(str[i]);
			if(flag == true)
				break;
			j += read_character( str[i] );
		}
		if(flag == true)
			printf("error\n");
		else
			printf("%ld\n", j);

		init();
	}
	return 0;
}