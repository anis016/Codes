#include<stdio.h>
#include<string.h>
#define MAX 200000

char str[MAX];

int stringcmp(char Hfir[MAX], char Hend[MAX])
{
	int i;
	int len = strlen(Hfir);
	for(i = 0; i < len; i++)
		if(Hfir[i] != Hend[i])
			return 1;
		
	return 0;
}

char Hfir[MAX], Hend[MAX], xx[MAX];

int main()
{
//	freopen("in.txt", "r", stdin);

	int Hlen, i, j, cnt, Case;

	scanf("%s", xx);
	sscanf(xx, "%d", &Case);
	while(Case--)
	{
		scanf("%s", str);
		int len = strlen(str);

		if(len == 1)
		{
			for(i = 0; i < 8; i++)
				printf("%c", str[0]);
			printf("...\n");
			continue;
		}

		Hlen = (len / 3);
		if(Hlen == 0)
			cnt = Hlen + 1;
		else
			cnt = Hlen;

		for( ; ; )
		{
			for(j = 0; j < cnt; j++)
				Hfir[j] = str[j];
			Hfir[j] = '\0';

			for(i = cnt, j = 0; j < cnt; j++, i++)
				Hend[j] = str[i];
			Hend[j] = '\0';
			
			if(stringcmp(Hfir, Hend)==1)
				cnt++;
			else
				break;
		}

		char temp[MAX];

		int Tlen = cnt * 2;
		for(i = Tlen, j = 0; i < len; i++)
			temp[j++] = str[i];
		temp[j] = '\0';

		for(i = 0; i < cnt; i++)
			if(temp[i] != Hfir[i])
				break;

		int Len = i;
		for(i = Len, j = 0; j < 8 && i < cnt; j++, i++)
			printf("%c", Hfir[i]);

		if(j >= 8)
		{
			printf("...\n");
			continue;
		}

		for(j = 0, i = 0; j < 8 - (cnt - Len);j++, i++)
		{
			if(Hfir[i] == NULL)
				i = 0;

			printf("%c", Hfir[i]);
		}
		printf("...\n");
	}
	return 0;
}