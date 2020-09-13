#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

typedef long Long;


long find_step(long n)  
{
	long j = 0,i;
	long sum = 0;
	for(i = 1; sum<n; i ++)  
	{
         sum += i;
		 j++;
	}
	return j;
}

void dec_inc(long step, long value)
{
	long diag_pos, num, den;

	diag_pos= ( step*(step+1) ) / 2;
	num=step;
	den=1;
	while(1)
	{
		if(value==diag_pos)
			break;

		diag_pos--;
		num--;
		den++;
	}

	printf("%ld/%ld\n", num, den);

	return ;
}

void inc_dec(long step, long value)
{
	long diag_pos, num, den;

	diag_pos= ( step*(step+1) ) / 2;
	num=1;
	den=step;
	while(1)
	{
		if(value==diag_pos)
			break;

		diag_pos--;
		num++;
		den--;
	}

	printf("%ld/%ld\n", num, den);

	return ;
}

int main()
{
	Long n, step;

	while(cin>>n)
	{
		cout<<"TERM "<<n<<" IS ";
		step=find_step(n);
		if( (step%2)==0)
		{
			dec_inc(step, n);
		}
		else
		{
			inc_dec(step, n);
		}
	}
	return 0;
}
