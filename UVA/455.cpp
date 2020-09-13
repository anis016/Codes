#include<stdio.h>
#include<string.h>
#define MAX 2100

char str[MAX];
char Hfir[MAX], Hend[MAX];

int main()
{
	int j, cnt, Case;

	for (scanf("%d", &Case); Case-- > 0 && scanf(" %s", str) == 1;)
	{
		int len = strlen(str);
		cnt = 1;

		for( ; ; )
		{
			for(j = 0; j < cnt; j++)
				Hfir[j] = str[j];
			Hfir[j] = '\0';

			int times = len / cnt;

			memset(Hend, 0, sizeof(Hend));
			for(j = 0; j < times; j++)
				strcat(Hend, Hfir);
				
			
			if(strcmp(str, Hend))
			{
				cnt++;
				memset(Hend, 0, sizeof(Hend));
			}
			else
 				break;
		}

		printf("%ld\n", cnt);
		if(Case > 0) 
			printf("\n");
	}
	return 0;
}

