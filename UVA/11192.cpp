#include<stdio.h>
#include<string.h>

int main()
{
	int g,len,num;
	int i,j;
	char str1[110];

	while(scanf("%d",&g),g!=0)
	{
		scanf("%s",str1);
		len=strlen(str1);

		if(g==1) 
		{
			for(j=len-1;j>=0;j--)
				printf("%c",str1[j]);
			printf("\n");
		}

		else
		{
			num=len/g;
	
			for(i=0;i<len;i+=num)
			{
				for(j=i+num-1;j>=i;--j)
					printf("%c",str1[j]);
			}
											
	
				printf("\n");
		}
	}
	
		return 0;
}