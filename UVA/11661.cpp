#include<stdio.h>
#include<string.h>
#define MAX 2000010

char str[MAX];

long check(long st, long len)
{
	long i, flag1, flag2, hor, hof;

	flag1 = 0;
	for(i=st-1; i>=0; i--)
	{
		if(str[i]=='D')
		{
			break;
		}

		if(str[i]=='R')
		{
			hor = (st - i);
			flag1 = 1;
			break;
		}
	}

	flag2 = 0;
	for(i=st+1; i<len; i++)
	{
		if(str[i]=='D')
		{
			break;
		}

		if(str[i]=='R')
		{
			hof = (i - st);
			flag2 = 1;
			break;
		}
	}

	if(flag1 == flag2)
	{
		if(flag1==1 && flag2==1)
		{
			if(hof < hor)
				return hof;
			else
				return hor;
		}
		else
			return -1;
	}
	else if(flag1==1)
		return hor;
	else
		return hof;
}

char xx[MAX];
int main()
{
	long len, i, count, min;
	
	while(gets(xx))
	{
		sscanf(xx, "%ld", &len);
		if(len==0)
			break;

		gets(str);
		min = 2000010;
		for(i=0; i<len; i++)
		{
			if(str[i]=='Z')
			{
				min = 0;
				break;
			}
			else
			{
				if(str[i]=='D')
				{
					count = check(i, len);

					if(count==-1)
						continue;

					if(count < min)
						min = count;
				}
			}
		}
		printf("%ld\n", min);
	}
	return 0;
}