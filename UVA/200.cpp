#include<stdio.h>
#include<string.h>
#define MAX 100000

char in[MAX][21];
char check[200], out[MAX], ch;

int main()
{
	long i, j, k, n, len, max;
	
	max=n=0;
	while(1)
	{
		gets(in[n]);
		len=strlen(in[n]);
		if(len>max)
			max=len;
		if(strcmp(in[n], "#")==0)
			break;
		n++;
	}

	j=0;
	k=0;
	while(j<max)
	{
		for(i=0; i<n; i++)
		{
			ch = in[i][j];
			if(check[ch]=='1' || ch==0)
			{
				continue;
			}
			else
			{
				check[ch]='1';
				out[k++] = ch;
			}
		}
		j++;
	}
	out[k]='\0';
	printf("%s\n", out);

	return 0;
}
/*
XWY
ZX
ZXY
ZXW
YWWX
*/