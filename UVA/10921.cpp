#include<stdio.h>
#include<string.h>

int main()
{
	char in[100];
	long i;

	while(gets(in))
	{
	   for(i=0; i<strlen(in); i++)
	   {
		if(in[i]=='A' || in[i]=='B' || in[i]=='C')
			printf("2");
		if(in[i]=='D' || in[i]=='E' || in[i]=='F')
			printf("3");
		if(in[i]=='G' || in[i]=='H' || in[i]=='I')
			printf("4");
		if(in[i]=='J' || in[i]=='K' || in[i]=='L')
			printf("5");
		if(in[i]=='M' || in[i]=='N' || in[i]=='O')
			printf("6");
		if(in[i]=='P' || in[i]=='Q' || in[i]=='R' || in[i]=='S')
			printf("7");
		if(in[i]=='T' || in[i]=='U' || in[i]=='V')
			printf("8");
		if(in[i]=='W' || in[i]=='X' || in[i]=='Y' || in[i]=='Z')
			printf("9");
		if(in[i]=='1')
			printf("1");
		if(in[i]=='0')
			printf("0");
		if(in[i]=='-')
			printf("-");
	   }
	   printf("\n");
	}
	return 0;
}

