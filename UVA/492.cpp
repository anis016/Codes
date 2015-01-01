#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 10000000

char in[MAX], ch;

int isvowel(char v_in)
{
	int flag = 0;

	if(v_in=='A' || v_in=='a')
		flag=1;
	else if(v_in=='E' || v_in=='e')
		flag=1;
	else if(v_in=='I' || v_in=='i')
		flag=1;
	else if(v_in=='O' || v_in=='o')
		flag=1;
	else if(v_in=='U' || v_in=='u')
		flag=1;
	
		return flag;
}

int main()
{
	long i=0, vowel=0, len=0;

	while(gets(in))
	{
		if(strcmp(in, " ")==0)
			continue;

		len=strlen(in);

		for(i=0; i<len; i++)
		{
    		if( isalpha(in[i]) )
			{
				ch=in[i++];
				vowel=isvowel(ch);
				
				if(vowel)
					printf("%c", ch);
				while(isalpha(in[i]) && i<len)
				{
					printf("%c", in[i]);
 					i++;
				}
				if(!vowel)
					printf("%c", ch);
				
				printf("ay");
				i--;
			}
			else
				printf("%c", in[i]);
		}
//		printf("\n");
	}
	return 0;
}