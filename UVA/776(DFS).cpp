#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXRR 250

char mat[MAXRR][MAXRR], ch;
long rep[MAXRR][MAXRR];

long maxr, maxc, cnt;
long R[] = {0, -1, 0, 1, -1, 1, -1, 1};
long C[] = {-1, 0, 1, 0, -1, -1, 1, 1};

bool is_alpha(char ch)
{
	if( ch != '.' )
		return true;
	return false;
}

void search(long row, long col)
{
	long i, nrow, ncol;

	mat[row][col] = '.';
	rep[row][col] = cnt;

	for(i=0; i<8; i++)
	{
		nrow = R[i] + row;
		ncol = C[i] + col;

		if(mat[nrow][ncol] == ch)
			search(nrow, ncol);
	}
	return ;
}

void process()
{
	long i, j;

	cnt = 1;
	for(i=0; i<maxr; i++)
		for(j=0; j<maxc; j++)
			if(is_alpha(mat[i][j]) == true)
			{
				ch = mat[i][j];
				search(i, j);
				cnt++;
			}
	return ;
}

void print()
{
	long i, j, ch, w[100000];

	for (i = 0; i < maxc; i++) 
	{
		for (ch = rep[0][i], j = 1; j < maxr; j++)
			if (rep[j][i] > ch) 
				ch = rep[j][i];

			for (j = 0; ch > 0; j++, ch /= 10);

			w[i] = j;
	}

	for (i = 0; i < maxr; i++) 
	{
		for (j = 0; j < maxc; j++)
			printf((j + 1) >= maxc ? "%*d\n" : "%*d ", w[j], rep[i][j]);
	}
	printf("%%\n");

	return ;
}

int main()
{
	long k;
	char c;

	while(1)
	{
		memset(mat, 0, sizeof(mat));

		maxr = k = 0;
		c = getchar();

		if(c == EOF)
			break;

		else if(c == '\n')
			continue;

		while(1)
		{
			if(c =='%')
				break;

			else if(c == '\n')
			{
				maxr++;
				maxc = k;
				k = 0;
			}

			else if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
			{
				mat[maxr][k] = c;
				k++;
			}

			c = getchar();
			if(c == EOF)
				break;
		}

		memset(rep, 0, sizeof(rep));	    
		process();
		print();

		maxr = maxc = cnt = 0;
	}
	return 0;
}