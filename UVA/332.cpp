#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

#define MAX 1000

char deci[MAX];
long j, kase=1;
double X;

long GCD(long a, long b) 
{ 
	return b? GCD(b, a%b):a;
}
void complex()
{
	long r, i, num, den, k,gcd;
	double up, down;

	X=atof(deci);
	
	r=0;		
	for(i=2; deci[i]!='\0'; i++)
		r++;
	k=r-j;

	up=X * pow(10,(k+j) ) - X * pow(10, k);
	down=pow(10, (k+j) ) - pow(10, k);

	den=(long)(ceil(down));
	num=(long)(ceil(up));

	gcd=GCD(den, num);
	
	printf("Case %ld: %ld/%ld\n", kase++, num/gcd, den/gcd);

	return ;
}

void simple()
{
	long r, i, up, k, down, num, den, gcd;

    char temp[MAX];
    for(i = 2, k=0; deci[i]; i++)
        temp[k++] = deci[i];

    temp[k] = '\0';
		
	r=0;		
	for(i=2; deci[i]!='\0'; i++)
		r++;

	down=1;
	for(i=1; i<=r; i++)
	{
		down=down*10;
	}

	up=down*X;

	den=down;
	num=atoi(temp);

	gcd=GCD(den, num);
	
	printf("Case %ld: %ld/%ld\n", kase++, num/gcd, den/gcd);

	return ;
}

int main()
{
//	freopen("332.in", "r", stdin);
//	freopen("332.out", "w", stdout);
	while(scanf("%ld", &j)==1)
	{
		if(j==-1)
			break;

		scanf("%s", deci);

		if(j == 0 && atof(deci) == 0.0)
		{
			printf("Case %ld: 0/1\n",kase++);
			continue;
		}

		if(j==0)
		{
			simple();
		}
		else
		{
			complex();
		}
	}
	return 0;
}
