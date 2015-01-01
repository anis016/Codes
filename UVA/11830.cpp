#include<stdio.h>
#include<string.h>
#define MAX 1001

char str[MAX], out[MAX];

void remove_zero()
{
	char temp[MAX + 100];
	int len, i, flag, k;

	flag = 0;
	len = strlen(out);
	for(i = 0, k = 0; i < len; i++)
		if(out[i] == '0' && flag == 0)
			continue;
		else
		{
			temp[k++] = out[i];
			flag = 1;
		}
	temp[k] = '\0';

	strcpy(out, temp);
	return ;
}

int main()
{
	char ch;
	int i, j;
	while(scanf("%c %s", &ch, str)==2)
	{
		if(ch == '0' && strcmp(str ,"0") == 0)
			break;

		int len = strlen(str);
		for(i = 0, j = 0; i < len; i++)
		{
			if(str[i] == ch)
				continue;

			out[j++] = str[i];
		}
		out[j] = '\0';

		remove_zero();
		if(strcmp(out, "")==0)
			printf("0\n");
		else
			printf("%s\n", out);
		
		getchar();
	}
	return 0;
}