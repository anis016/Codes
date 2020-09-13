#include<iostream>
using namespace std;

int main()
{
	long long in, out, mid, flow=0, flow2=0, n, i;

	cin>>n;
	for(i=0; i<n; i++)
	{
	cin>>in;

	mid=(((((((in*567)/9)+7492)*235))/47)-498);
	flow=mid/10;
	flow2=flow%10;

	out=flow2;

	if(out<0)
	cout<<out*-1<<endl;
	else
	cout<<out<<endl;

	}
	return 0;

}