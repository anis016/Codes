#include<stdio.h>
//#include<math.h>

long n;

long check(long s)
{
	long flag = 0;
	long i, j, k, l, m;

	k = 0;
	while(1)
	{
		i = (n-1) / s;
		m = (n-1) % s;
		
		if(m != 0)
			return 1;

		j = (n-1) - i;
		n = j;
		k++;

		if(k==s)
		{
			l = i%s;
			if(l==0)
				return 0;
			else
				return 1;
		}
	}
}

int main()
{
	long i, flag, s;
	while(scanf("%ld", &n)==1)
	{
		if(n<0)
			break;

		s = n;
		
		flag = 1;
	//	for(i=ceil((double)sqrt(n)); i>=2; i--)
		for(i=9; i>=2; i--)
		{
			flag = check(i);
			if(flag==1)
			{
				n = s;
				continue;
			}
			else
				break;
		}

		if(flag == 0)
			printf("%ld coconuts, %ld people and 1 monkey\n", s, i);
		else
			printf("%ld coconuts, no solution\n", s);
	}
	return 0;
}

/*

25

(25-1)/3=8

so after first person, still 16 coconuts left.

(16-1)/3=5

so after second person, still 10 coconuts left.

and after third person, 6 coconuts left. ----> result

AND,

6 can be divide by 3, so 3 people is right.

if the result can not divide by 3, you should calculate next. 

*/