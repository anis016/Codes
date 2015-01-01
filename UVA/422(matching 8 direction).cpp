#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 10000

char mat[MAX][MAX], word[MAX];
long N, R, C;

long DOWN(long r, long c)
{
	long i;

	for(i=0; word[i]; i++)
	{
		if(r >= N)
			return 0;

		if(word[i] != mat[r++][c])
			return 0;
	}

	R = r - 1;
	C = c;

	return 1;
}

long UP(long r, long c)
{
	long i;

	for(i=0; word[i]; i++)
	{
		if(r < 0)
			return 0;

		if(word[i] != mat[r--][c])
			return 0;
	}

	R = r + 1;
	C = c;

	return 1;
}

long LEFT(long r, long c)
{
	long i;

	for(i=0; word[i]; i++)
	{
		if( c >= N)
			return 0;

		if(word[i] != mat[r][c++])
			return 0;
	}

	R = r;
	C = c - 1;

	return 1;
}

long RIGHT(long r, long c)
{
	long i;

	for(i=0; word[i]; i++)
	{
		if( c < 0)
			return 0;

		if(word[i] != mat[r][c--])
			return 0;
	}

	R = r;
	C = c + 1;

	return 1;
}

long DNE(long r, long c)
{
	long i;

	for(i=0; word[i]; i++)
	{
		if( r<0 || c>=N)
			return 0;

		if(word[i] != mat[r--][c++])
			return 0;
	}

	R = r + 1;
	C = c - 1;

	return 1;
}

long DSE(long r, long c)
{
	long i;

	for(i=0; word[i]; i++)
	{
		if( r>=N || c>=N)
			return 0;

		if(word[i] != mat[r++][c++])
			return 0;
	}

	R = r - 1;
	C = c - 1;

	return 1;
}

long DWS(long r, long c)
{
	long i;

	for(i=0; word[i]; i++)
	{
		if( r>=N || c<0)
			return 0;

		if(word[i] != mat[r++][c--])
			return 0;
	}

	R = r - 1;
	C = c + 1;

	return 1;
}

long DWN(long r, long c)
{
	long i;

	for(i=0; word[i]; i++)
	{
		if( r<0 || c<0)
			return 0;

		if(word[i] != mat[r--][c--])
			return 0;
	}

	R = r + 1;
	C = c + 1;

	return 1;
}

long find(long r, long c)
{
	     if(UP(r, c) == 1)
		return 1;
	else if(DOWN(r, c) == 1)
		return 1;
	else if(LEFT(r, c) == 1)
		return 1;
	else if(RIGHT(r, c) == 1)
		return 1;
	else if(DNE(r, c) == 1)
		return 1;
	else if(DSE(r, c) == 1)
		return 1;
	else if(DWS(r, c) == 1)
		return 1;
	else if(DWN(r, c) == 1)
		return 1;
	return 0;
}

void process()
{
	long i, j, r, c, flag;

	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(word[0] == mat[i][j])
			{
				r = i;
				c = j;

				flag = find(r, c);
				if(flag == 1)
				{
					printf("%ld,%ld %ld,%ld\n", r+1, c+1, R+1, C+1);
					return ;
				}
			}
	
	printf("Not found\n");	  
	return ;
}


int main()
{
//	freopen("in.txt", "r", stdin);
	
	static char buf[MAX];
	long i;

	while(gets(buf))
	{
		sscanf(buf, "%ld", &N);
		if(N == 0)
			break;

		for(i=0; i<N; i++)
			scanf("%s", mat[i]);

		getchar();
		while(gets(word))
		{
			sscanf(word, "%ld", &N);
			if(N == 0)
				break;

			R = C = 0;
			process();
		}
	}
	return 0;
}
