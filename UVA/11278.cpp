#include<stdio.h>
#include<string.h>

int main()
{
	char l[]="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./\\~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    char r[]="`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'\\~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

	char in[2000];
	long len, i, j;

	
	while(gets(in))
	{
		len=strlen(in);
		
		for(i=0; i<len; i++)
		{
			if(in[i]==' ')
			{
				printf(" ");
				continue;
			}
			for(j=0; j<=94; j++)
			{
				if(l[j]==in[i])
				{
					printf("%c", r[j]);
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}