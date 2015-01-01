#include<stdio.h>
#define MAX 110

char st[MAX];
int n;

int main()
{
    int Case = 1, i, k;
	char ch;

	while(scanf("%d",&n), n)
	{
		getchar();

		printf("Case %d:\n", Case++);
		printf("#include<string.h>\n");
        printf("#include<stdio.h>\n");
		printf("int main()\n{\n");

		for(k=0; k<n; )
		{
			ch = getchar();

			if(ch == '\n')
				continue;
			else
			{
				i = 0;

				st[i++] = ch;
				while(1)
				{
					ch = getchar();

					if(ch == '\n')
						break;
					
					st[i++] = ch;
				}
			}

			printf("printf(\"");
			for(i=0;st[i];i++)
			{
				if(st[i] == 34 || st[i] == 92)
					printf("\\");

				printf("%c",st[i]);
				st[i] = 0;
			}
			printf("\\n\");\n");
			k++;
		}
		printf("printf(\"\\n\");\n");
		printf("return 0;\n");
		printf("}\n");
	}
    return 0;
}
