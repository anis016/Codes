#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 600

char list[MAX][20];

int main()
{
	char s[20], v[20];
	long i, j, len, len1, dataSet, ii, count, flag, st, testcase;

	scanf("%ld", &testcase);

	while(testcase--)
	{
		scanf("%ld",&dataSet);
		
		for(ii=0;ii<dataSet;ii++)
		{
			scanf("%s",list[ii]);
		}
		
		while(1)
		{
			flag=1;
			scanf("%s", s);

			if(strcmp(s, "END")==0)
				break;

			strcpy(v, s);
			printf("Anagrams for: %s\n", v);
			len=strlen(s);
			
			st=count=0;
			while(1)
			{
				for(ii=0; ii<dataSet; ii++)
				{
					len1=strlen(list[ii]);
					if(len==len1)
					{
						count=0;
						for(i=0; i<len; i++)
						{
							for(j=0; j<len; j++)			
							{
								if(list[ii][i]==s[j] && s[j]!=1)						
								{
									s[j]='1';
									count++;
									break;
								}
							}
						}
					}
					if(count==len)
					{	
						printf("%3ld) %s\n", flag++, list[ii]);
						strcpy(s, v);
						count=0;
						st=1;				
					}			
					else				
					{
						strcpy(s, v);
						count=0;
					}
				}
				if(ii==dataSet)			
					break;	
			}
			if(st==0)
			{		
				printf("No anagrams for: %s\n", v);
				strcpy(s, v);
				count=0;
			}
		}
		if(testcase>=1)
			printf("\n");
	}
	return 0;
}