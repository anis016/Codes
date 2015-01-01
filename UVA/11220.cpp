#include<stdio.h>
#include<string.h>
#define MAX 5000

char in[MAX], *ch, xx[MAX], list[MAX];

int main()
{
	long len, count, test, j;

	gets(xx);
	sscanf(xx, "%ld", &test);

	gets(in);
	for(j=1; j<=test; j++)
	{
		if(j!= 1)
            printf("\nCase #%ld:\n", j);
        else
            printf("Case #%ld:\n", j);

		while(gets(in))
		{
			if(strlen(in)==0)
				break;

			ch=strtok(in, " ");
			
			count=0;
			while(ch!=NULL)
			{
				strcpy(list, ch);
				len=strlen(list);
				if(len>count)		
				{
					printf("%c", list[count]);
					count++;
				}

				ch=strtok(NULL, " ");
			}			
			printf("\n");
			memset(list, '\0', sizeof(list));
		}
	}
	return 0;
}