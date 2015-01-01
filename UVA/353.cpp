#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char str[MAX];
char container[MAX][85];
int maximum;

int com(const void *a , const void *b) 
{
   return strcmp( (char *)a, (char *)b );
}

bool palindrome(char *s)
{
	int len = strlen(s);
	int length = 0;
	
	if( (len % 2) == 1 )
		length = len / 2 + 1;
	else
		length = len / 2;

	int i = 0;
	int j = len - 1;

	for(i = 0, j = len - 1; i < length; j--, i++)
	{
		if(s[i] != s[j])
			return false;
	}
	return true;
}

bool Bsearch(char *s)
{
	int high = maximum - 1;
	int low = 0;
	int mid = 0;
	int f;

	while(low <= high)
	{
		mid = (int) (low + high) / 2;

		f = strcmp(s, container[mid]);
		if(f > 0)
			low = mid + 1;
		else if(f < 0)
			high = mid - 1;
		else if(f == 0)
			return true;
	}
	return false;
}

int make_word()
{
	char temp[MAX];
	char tempo[MAX];

	int len = strlen(str);
	int i, j, k;

	strcpy(tempo, str);

	int K = 0;
	for(i = 0; str[i]; i++)
	{
		if(tempo[i] != '.')
			K++;

		for(j = i + 1; str[j]; j++)
		{
			if(str[i] == str[j])
			{
				tempo[j] = '.';

				int t = 0;
				for(k = i; k <= j; k++)
					temp[t++] = str[k];
				temp[t] = '\0';

				bool f = Bsearch(temp);
				if(f == false)
				{
					bool p = palindrome(temp);
					if(p == true)
					{
						strcpy(container[maximum], temp);
						qsort(container, maximum, sizeof(container[0]), com);
						maximum++;
					}
				}
			}
		}
	}
	return (maximum + K);
}

int main()
{
//	freopen("in.txt", "r", stdin);

	while(gets(str))
	{
		int len = 0;

		maximum = 0;
		len = make_word();

		printf("The string '%s' contains %ld palindromes.\n", str, len);
	}
	return 0;
}