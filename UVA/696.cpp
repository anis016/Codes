#include<stdio.h>
#define swap(xxx, yyy) xxx^=yyy^=xxx^=yyy

long knight[3][505];

void init(void )
{
	long i, count = 0;

	for(i=1; i<=500; i++)
	{
		if(i%4==3 || i%4==0)
			count;
		else
			count++;
		
		knight[1][i] = count;
		knight[2][i] = 2 * knight[1][i];		
	}
	return ;
}

int main()
{
	long r, c, res, fr, fc;

	init();

	while(scanf("%ld %ld", &r, &c)==2)
	{
		if(r==0 && c==0)
			break;

		if(r==0 || c==0)
		{
			printf("0 knights may be placed on a %ld row %ld column board.\n", r, c);
			continue;
		}
		fr = r;
		fc = c;
		if(fc < fr)
			swap(fc, fr);

		if(c>=3 && r>=3)
		{
			res = ( (r * c) + 1) / 2 ;
			printf("%ld knights may be placed on a %ld row %ld column board.\n", res, r, c);
		}
		else if(fr==2)
		{
			printf("%ld knights may be placed on a %ld row %ld column board.\n", knight[2][fc], r, c);
		}
		else if(fr==1)
		{
			printf("%ld knights may be placed on a %ld row %ld column board.\n", fc, r, c);
		}
	}

	return 0;
}