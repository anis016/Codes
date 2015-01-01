#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 1000

double R[MAX][100];
long store[100][MAX], rr;

double rect_rx, rect_lx, rect_ry, rect_ly;


int main()
{	
	char in;
	long i, r, c, test, j, k, w, flag, re, ci, kase;
	double x, y;
	
	i=r=c=rr=k=test=0;
	while(1)
	{
		cin>>in;

		if(in=='*')
			break;
		else
		{			
			cin>>R[r][0]>>R[r][1]>>R[r][2]>>R[r][3];
			store[1][r]=++test;
			r++;
		}
		i++;
	}

	re=ci=w=0;
	kase=0;
	while(1)
	{
		cin>>x>>y;
		kase=kase+1;

		re=ci=flag=0;
	   	if(x==9999.9 && y==9999.9)
			break;
		else
		{
			j=0;
			for( ; j<i; re++, j++)
			{
				if((x > R[j][0])&&(x < R[j][2])&&(y < R[j][1])&&(y > R[j][3])) 
				{
					printf("Point %ld is contained in figure %ld\n", kase, store[1][re]);
					flag=1;
				}
				if(store[1][re]==0)
				break;
            }
			if(flag==0)
				printf("Point %ld is not contained in any figure\n", kase);
		}
	}
	
	return 0;
}
