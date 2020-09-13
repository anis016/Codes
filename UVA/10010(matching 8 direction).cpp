#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 10000

char GRID[MAX][51];
char WORD[55];
long M,N,WW,R,C;

long HF(long r,long c) 
{
  long i;

  for(i = 0; WORD[i]; i ++)
    if(WORD[i] != GRID[r][c++]) 
		return 0;

  R = r;
  C = c-1;
  return 1;
}

long HB(long r,long c) 
{
  long i;

  for(i = 0; WORD[i]; i ++) 
  {
	  if(c<0) 
		  return 0;
	  if(WORD[i] != GRID[r][c--]) 
		  return 0;
  }
  R = r;
  C = c+1;
  return 1;
}

long VF(long r,long c) 
{
  long i;

  for(i = 0; WORD[i]; i ++)  
  {
	  if(r>=M) 
		  return 0;
	  if(WORD[i] != GRID[r++][c]) 
		  return 0;
  }
  R = r-1;
  C = c;
  return 1;
}

long VB(long r,long c) 
{
	long i;

	for(i = 0; WORD[i]; i ++) 
	{
		if(r<0) 
			return 0;
		if(WORD[i] != GRID[r--][c]) 
			return 0;
	}
	R = r+1;
	C = c;
	return 1;
}

long DWN(long r,long c) 
{
	long i;

	for(i = 0; WORD[i]; i ++) 
	{
		if(r<0 ||c<0) 
			return 0;
		if(WORD[i] != GRID[r--][c--]) 
			return 0;
	}
	R = r+1;
	C = c+1;
	return 1;
}

long DNE(long r,long c) 
{
	long i;

	for(i = 0; WORD[i]; i ++) 
	{
		if(r<0 || c>=N) 
			return 0;
		if(WORD[i] != GRID[r--][c++]) 
			return 0;
	}
	R = r+1;
	C = r-1;
	return 1;
}

long DES(long r,long c) 
{
	long i;

	for(i = 0; WORD[i]; i ++) 
	{
		if(r>=M ||c>=N) 
			return 0;
		if(WORD[i] != GRID[r++][c++]) 
			return 0;  
	}
	R = r-1;
	C = c-1;
	return 1;
}

long DSW(long r,long c) 
{
	long i;

	for(i = 0; WORD[i]; i ++) 
	{
		if(r>=M ||c<0) 
			return 0;    
		if(WORD[i] != GRID[r++][c--]) 
			return 0;
	}
	R = r-1;
	C = c+1;
	return 1;
}

long CHECK(long r,long c) 
{

	if(HF(r,c))
		return 1;
	else if(HB(r,c))
		return 1;
	else if(VF(r,c))
		return 1;
	else if(VB(r,c))
		return 1;
	else if(DWN(r,c))
		return 1;
	else if(DNE(r,c))
		return 1;
	else if(DES(r,c))
		return 1;
	else if(DSW(r,c))
		return 1;
	return 0;
}

long SOLVECASE() 
{
   long p,q;
    for(p = 0; p<M; p++)
		for(q =0;q<N; q++)
			if(WORD[0] == GRID[p][q])
				if(CHECK(p,q))
					goto done;

     done:;
		  printf("%d %d\n",p+1,q+1);

	return 0;
}

int main() 
{
	long Case, i, j;
	
	static char input[MAX],fal[MAX];
	
	gets(input);
	sscanf(input,"%ld",&Case);
	while(Case --)
	{
		gets(fal);
		gets(input);
		sscanf(input,"%ld %ld",&M,&N);
		for(i = 0; i<M; i ++) 
		{
			gets(GRID[i]);
			for(j = 0; GRID[i][j]; j ++)
				GRID[i][j] = tolower(GRID[i][j]);
		}
		gets(input);
		sscanf(input,"%d",&WW);
		for(i = 0 ;i<WW; i++) 
		{
			gets(WORD);
	
			for(j = 0; WORD[j]; j ++)
				WORD[j] = tolower(WORD[j]);
		
			SOLVECASE();
		}

		if(Case) 
			printf("\n");
	}
	return 0;
}

