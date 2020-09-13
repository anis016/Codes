#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

typedef long Long;

int main()
{
	Long n, x, y, num, den;

	while(cin>>n)
	{
		x=sqrt(2.0*n+0.25) - 0.5 ;
		y=( x*(x+1) ) / 2.0 ;
		
		if(y==n)
			cout<<1<<"/"<<x<<endl;
		else
		{
			num=x+y-n+2;
			den=n-y;
			cout<<num<<"/"<<den<<endl;
		}
	}
	return 0;
}
