#include<stdio.h>
#include<string.h>
#define MAX 100

char judge[MAX], contest[MAX];

bool accepted(char *j, char *c)
{
	if(strcmp(j, c)==0)
		return true;
	else
		return false;
}

bool output_format(char *jud, char *con)
{
	long i, j;
	long l1, l2;
	bool flag = false;

	l1=strlen(jud);
	l2=strlen(con);

	for(i=0, j=0; i<l1; i++)
	{
		if(jud[i] == ' ')
			continue;
		else
			jud[j++] = jud[i];
	}
	jud[j] = '\0';

	for(i=0, j=0; i<l2; i++)
	{
		if(con[i] == ' ')
			continue;
		else
			con[j++] = con[i];
	}
	con[j] = '\0';

	flag = accepted(jud, con);

	if(flag==true)
		return true;
	else
		return false;

}

int main()
{
	char xx[MAX];
	long test, count=1;
	bool flag;

	gets(xx);
	sscanf(xx, "%ld", &test);
	while(test--)
	{
		flag=false;

		gets(contest);
		gets(judge);

		flag = accepted(contest, judge);
		if(flag==true)
		{
			printf("Case %ld: Yes\n", count++);
			continue;
		}
		else
		{
			flag = output_format(contest, judge);
			if(flag==true)
			{
				printf("Case %ld: Output Format Error\n", count++);
				continue;
			}
			
			if(flag == false)
				printf("Case %ld: Wrong Answer\n", count++);
		}

	}

	return 0;
}