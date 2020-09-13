#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	char in[1000][1000];
	long i, j, row, max, hold[1000];

	row=max=0;
	while(gets(in[row]))
	{
		hold[row]=strlen(in[row]);
		if(hold[row]>max)
			max=hold[row];
		row++;
	}

	for(i=0; i<row; i++)
	{
		if(hold[i]<max)
		{
			for(j=hold[i]; j<max; j++)
				in[i][j]=' ';
			in[i][j]='\0';
		}
	}

	for(j=0; j<max; j++)
	{
		for(i=row-1; i>=0; i--)
			printf("%c", in[i][j]);
		printf("\n");
	}

    return 0;
}

