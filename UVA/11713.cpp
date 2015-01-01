#include<stdio.h>
#include<string.h>
#define MAX 10000

int check_vowel(char c)
{
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return 1;
	else
		return 0;
}

int main()
{
	char xx[MAX], str1[MAX], str2[MAX];
	long len1, len2, n, check1, check2, flag, i;

	gets(xx);
	sscanf(xx, "%ld", &n);

	while(n--)
	{
		gets(str1);
			gets(str2);

		len1=len2=flag=0;

		len1=strlen(str1);
		len2=strlen(str2);

		if(len1==len2)
		{
			check1=0;

			for(i=0; i<len1; i++)
			{
				check1=check_vowel(str1[i]);

				if(check1==0)
				{
					if(str1[i]!=str2[i])
					{
						flag=1;
						break;
					}
					else
						continue;
				}
				else
				{
					check2=check_vowel(str2[i]);
					if(check2==check1)
						continue;
					else
					{
						flag=1;
						break;
					}
				}
			}
		}
		else
		{
			flag=1;
		}

		if(flag==1)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}		
	}
	return 0;
}