#include<cstdio>
#include<iostream>
#include<math.h>
using namespace std;

#define EPSILON pow(10,-9)

typedef long tall; 
 
long in[100];
long HH[100], MM[100], SS[100], CC[100], hold[100], i, j;
double get_hour, hh, mm, ss, cc;
long get_deci;

int main()
{
	while(scanf("%ld", &in)!=EOF)
	{
		get_deci=get_hour=0;

		if(in[0]==0)
			cout<<"0000000"<<endl;
		else
		{

		HH[0]=in[0]/10000000;
		hold[0]=in[0]%10000000;
		HH[1]=hold[0]/1000000;

		hh=(HH[1]+10*HH[0]) * (360000);
		hold[0]=in[0]%1000000;
		
		MM[0]=hold[0]/100000;
		hold[0]=in[0]%100000;
		MM[1]=hold[0]/10000;

		mm= (MM[1]+10*MM[0]) * (6000);
		hold[0]=in[0]%10000;

		SS[0]=hold[0]/1000;
		hold[0]=in[0]%1000;
		SS[1]=hold[0]/100;

		ss=(SS[1]+10*SS[0]) * (100);
		hold[0]=in[0]%100;

		CC[0]=hold[0]/10;
		hold[0]=in[0]%10;
		CC[1]=hold[0]/1;

		cc=(CC[1]+10*CC[0]);

//		get_hour=(hh*60*60*100)+(mm*60*100)+(ss*100)+cc;
		get_hour=hh+mm+ss+cc;
		get_deci =(get_hour*(125.0/108.0) )+EPSILON;
		printf("%07ld\n", get_deci);

		}
	}	
	return 0;
}
