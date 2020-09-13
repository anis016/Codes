#include<stdio.h>
#include<string.h>

#define MAX 10000
char str[MAX];

char find_sign(char str[MAX])
{
	int i;
	char ch;
	for(i = 0; str[i]; i++)
		if(str[i] == '+' || str[i] == '-')
		{
			ch = str[i];
			return ch;
		}
}

int main()
{
	char *p;
	long fir, sec, res;
	int cor = 0;
	while(gets(str))
	{
		char ch = find_sign(str);
		fir = res = sec = -1;

		int flag = 0, cnt = 0;

		if(strcmp(str, "")==0)
			break;

		p = strtok(str, "+-=");
		while(p != NULL)
		{
			if(flag == 0)
				sscanf(p, "%ld", &fir);
			else if(flag == 1)
				sscanf(p, "%ld", &sec);
			else if(flag == 2)
				sscanf(p, "%ld", &res);

			p = strtok(NULL, "+-=");
			flag++;
		}

		if(res == -1)
			continue;

		if(ch == '+')
		{
			if( (fir + sec) == res)
				cor++;
		}

		if(ch == '-')
		{
			if( (fir - sec) == res)
				cor++;
		}
	}

	printf("%d\n", cor);
	return 0;
}